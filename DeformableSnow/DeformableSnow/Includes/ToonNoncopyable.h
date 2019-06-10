#ifndef TOON_NONCOPYABLE_H
#define TOON_NONCOPYABLE_H

namespace Toon
{
	class Noncopyable
	{
	public:
		Noncopyable() = default;
		Noncopyable(Noncopyable const&) = delete;
		Noncopyable(Noncopyable&&	  ) = delete;
		Noncopyable& operator=(Noncopyable const&) = delete;
		Noncopyable& operator=(Noncopyable&&	 ) = delete;
	};
};

#endif //TOON_NONCOPYABLE_H