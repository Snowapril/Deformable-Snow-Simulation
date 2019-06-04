#ifndef STATIC_STRING_H
#define STATIC_STRING_H

#include <cstddef>

namespace ToonResourceParser
{
	class StaticString
	{
	public:
		template < std::size_t N >
		constexpr StaticString(char const (&)[N]) noexcept;
		constexpr StaticString(char const*, std::size_t) noexcept;
		constexpr StaticString() = default;

		constexpr std::size_t size(void) const noexcept;
		constexpr char const* c_str(void) const noexcept;
		constexpr auto begin(void) const noexcept;
		constexpr auto end(void)   const noexcept;
	private:
		std::size_t len{ 0 };
		char const* buffer = nullptr;
	};

	template < std::size_t N >
	constexpr StaticString::StaticString(char const (&str)[N]) noexcept
		: buffer{ str }, len{ N - 1 }
	{

	}
	constexpr StaticString::StaticString(char const* str, std::size_t size) noexcept
		: buffer{ str }, len{ size }
	{

	}
	constexpr std::size_t StaticString::size(void) const noexcept
	{
		return len;
	}
	constexpr char const* StaticString::c_str(void) const noexcept
	{
		return buffer;
	}

	constexpr auto StaticString::begin(void) const noexcept
	{

	}

	constexpr auto StaticString::end(void) const noexcept
	{

	}
};

#endif