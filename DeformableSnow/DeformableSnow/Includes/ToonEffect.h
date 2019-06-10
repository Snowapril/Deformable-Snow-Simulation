/**
 * @file ToonGL3PlusEffect.h
 * @author snowapril (https://github.com/Snowapril)
 * @brief provide useful methods such as compiling GLSL binary file (What DirectX is doing)
 * @version 0.1
 * @date 2019-05-14
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef EFFECT_H
#define EFFECT_H

namespace Toon
{
	/****************************************************************************
						Effect class declaration
	****************************************************************************/
	class Effect
	{
	private:
		int effect = 0;
	public:
		Effect() = default;
		~Effect();

		void create() noexcept;
		void release() noexcept;

		int 		compileProgram(char const* effectFilePath, char const* programName) const;
		char const* getProgramName(int programIndex) const;
	private:
		void		handleGLFXError(void) const;
	};
};

#endif