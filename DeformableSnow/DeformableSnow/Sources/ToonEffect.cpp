#include "stdafx.h"
#include "ToonEffect.h"
#include <string>
#include <GLFX/glfx.h>
#include "ToonLogger.h"

namespace Toon
{
	/****************************************************************************
						GL3PlusEffect class definition
	****************************************************************************/

	Effect::~Effect()
	{
		release();
	}

	void Effect::create() noexcept
	{
		effect = glfxGenEffect();
	}

	void Effect::release() noexcept
	{
		if (effect != 0) glfxDeleteEffect(effect);
	}

	int Effect::compileProgram( char const* effectFilePath, char const* programName ) const
	{
		bool bParsingSuccess = glfxParseEffectFromFile( effect, effectFilePath );
		if (!bParsingSuccess)
		{
			handleGLFXError();
			return -1;
		}

		int program = glfxCompileProgram( effect, programName );
		if (program == -1)
		{
			handleGLFXError();
			return -1;
		}

		return program;
	}

	char const* Effect::getProgramName( int programIndex ) const
	{
		return glfxGetProgramName( effect, programIndex );
	}

	void Effect::handleGLFXError(void) const
	{
		std::string errorLog = glfxGetEffectLog(effect);
		Logger::getConstInstance().errorMessage("{}", errorLog);
	}
};