#ifndef EFFECT_H
#define EFFECT_H

namespace Toon
{
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