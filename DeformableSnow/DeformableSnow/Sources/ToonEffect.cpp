#include "stdafx.h"
#include "ToonEffect.h"

#include <gl/glfx.h>
#include <glew/glew.h>
#include <iostream>
#include <string>

/*
Check GLFX document at https://github.com/maizensh/glfx
*/

namespace Toon
{
	/****************************************************************************
						GL3PlusEffect class definition
	****************************************************************************/

	Effect::Effect(Effect const& other) noexcept
		: super_t(other)
	{
	}

	Effect& Effect::operator=(Effect const& other) noexcept
	{
		if (this != &other)
		{
			objectID = other.objectID;
		}

		return *this;
	}

	Effect::Effect(Effect&& other) noexcept
		: super_t(std::move(other))
	{
	}

	Effect& Effect::operator=(Effect&& other) noexcept
	{
		if (this != &other)
		{
			objectID = other.objectID;
			other.objectID = 0U;
		}

		return *this;
	}

	Effect::~Effect() noexcept
	{
		release();
	}

	bool Effect::init() noexcept
	{
		objectID = glfxGenEffect();
		return true;
	}

	void Effect::release() noexcept
	{
		if (objectID != 0) glfxDeleteEffect(objectID);
	}

	void Effect::bind() const noexcept
	{
		glUseProgram(objectID);
	}

	int Effect::compileProgram( char const* effectFilePath, char const* programName ) const
	{
		bool bParsingSuccess = glfxParseEffectFromFile(objectID, effectFilePath );
		if (!bParsingSuccess)
		{
			handleGLFXError();
			return -1;
		}

		int program = glfxCompileProgram(objectID, programName );
		if (program == -1)
		{
			handleGLFXError();
			return -1;
		}

		return program;
	}

	char const* Effect::getProgramName( int programIndex ) const
	{
		return glfxGetProgramName(objectID, programIndex );
	}

	void Effect::handleGLFXError(void) const
	{
		std::string errorLog = glfxGetEffectLog(objectID);
		std::cerr << errorLog << std::endl;
	}
};