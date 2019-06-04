#ifndef MAP_H
#define MAP_H

#include <array>
#include "Utility.h"

namespace ToonResourceParser 
{
	template <typename Key, typename Value, std::size_t Size>
	class Map
	{
	public:
		using storage_t  = std::array<Pair<Key, Value>, Size>;
		using size_type  = std::size_t;
		using key_type   = typename Key;
		using value_type = typename Value;

		constexpr Map() = default;
		template < typename Iter >
		constexpr Map(Iter, Iter) noexcept;
	public:
		constexpr value_type& operator[](key_type const&) noexcept;
		constexpr value_type const& operator[](key_type const&) const noexcept;

		constexpr auto begin(void) noexcept;
		constexpr auto end(void) noexcept;

		constexpr auto find(key_type const&) const noexcept;
	private:
		storage_t storage{};
		size_type numElements{ 0 };
	};

	template <typename Key, typename Value, std::size_t Size>
	template < typename Iter >
	constexpr Map<Key, Value, Size>::Map(Iter _begin, Iter _end) noexcept
		: numElements(std::distance(_begin, _end))
	{
		int i{ 0 };
		for (auto iter = _begin; iter != _end; ++iter)
		{
			storage[i++] = *iter;
		}
	}

	template <typename Key, typename Value, std::size_t Size>
	constexpr typename Map<Key,Value, Size>::value_type& Map<Key, Value, Size>::operator[](key_type const& key) noexcept
	{
		auto iter = find(key);
		auto end_iter = end();

		static_assert(iter != end_iter);

		return iter->second;
	}
	template <typename Key, typename Value, std::size_t Size>
	constexpr typename Map<Key, Value, Size>::value_type const& Map<Key, Value, Size>::operator[](key_type const& key) const noexcept
	{
		auto iter = find(key);
		auto end_iter = end();

		static_assert(iter != end_iter);

		return iter->second;
	}
	template <typename Key, typename Value, std::size_t Size>
	constexpr auto Map<Key, Value, Size>::begin(void) noexcept
	{
		return std::begin(storage);
	}
	template <typename Key, typename Value, std::size_t Size>
	constexpr auto Map<Key, Value, Size>::end(void) noexcept
	{
		return std::begin(storage) + numElements;
	}

	template <typename Key, typename Value, std::size_t Size>
	constexpr auto Map<Key, Value, Size>::find(key_type const& key) const noexcept
	{
		for (auto iter = begin(); iter != end(); ++iter)
		{
			if (iter->first == key) return iter;
		}

		return end();
	}
};

#endif