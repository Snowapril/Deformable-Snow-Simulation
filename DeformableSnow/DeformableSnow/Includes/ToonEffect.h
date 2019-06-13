#ifndef EFFECT_H
#define EFFECT_H

#include "ToonBaseObject.h"

namespace Toon
{
	class Effect : public BaseObject
	{
	public:
		Effect() = default;
		Effect(Effect const&) noexcept;
		Effect& operator=(Effect const&) noexcept;
		Effect(Effect&&) noexcept;
		Effect& operator=(Effect&&) noexcept;
		~Effect() noexcept;

		bool init() noexcept override;
		void release() noexcept override;
		void bind() const noexcept override;
		void unbind() const noexcept override {};
		void bindToGPU(bool _deleteAfterPush = false) noexcept override {};
	public:
		int 		compileProgram(char const* effectFilePath, char const* programName) const;
		char const* getProgramName(int programIndex) const;
	private:
		void		handleGLFXError(void) const;
	};
};

#endif