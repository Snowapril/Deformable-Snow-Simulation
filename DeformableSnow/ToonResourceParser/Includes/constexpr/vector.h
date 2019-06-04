#ifndef VECTOR_H
#define VECTOR_H

#include <initializer_list>
#include <type_traits>
#include <array>
#include "Utility.h"

namespace ToonResourceParser 
{
    template < typename Type, std::size_t Size >
    class Vector
    {
    public:
		using storage_t		 = std::array<Type, Size>;
		using size_type		 = std::size_t;
		using iterator		 = typename storage_t::iterator;
		using const_iterator = typename storage_t::const_iterator;

        constexpr Vector() noexcept;
		template < typename... T>
		constexpr Vector(T&&...) noexcept;
		template < typename Iter >
		constexpr Vector(Iter, Iter) noexcept;

        template < typename T, typename Enable = typename std::enable_if_t< std::is_same_v< Type, T >> >
        constexpr void push_back(T&&) noexcept;
        constexpr void pop_back(void) noexcept;
        template < typename... T, typename Enable = typename std::enable_if_t< std::is_constructible_v< Type, T... >> >
        constexpr void emplace_back(T&&...) noexcept;
        constexpr Type const & front(void) const noexcept;
        constexpr size_type size(void) const noexcept;
        constexpr bool empty(void) const noexcept;
        constexpr auto begin(void) const noexcept;
        constexpr auto end(void) const noexcept;
	protected:
		storage_t storage {};
		size_type numElements {0};
    };

	template < typename Type, std::size_t Size >
	constexpr Vector< Type, Size >::Vector() noexcept
		: storage{}, numElements(0)
	{
	}
	template < typename Type, std::size_t Size >
	template < typename... T >
	constexpr Vector< Type, Size >::Vector(T&&... args) noexcept
		: storage{ std::forward<Type>(args)... }, numElements(sizeof...(args))
	{	
	}

	template < typename Type, std::size_t Size >
	template < typename Iter >
	constexpr Vector<Type, Size>::Vector(Iter _begin, Iter _end) noexcept
		: numElements(std::distance(_begin, _end))
	{
		int i{ 0 };
		for (auto iter = _begin; iter != _end; ++iter)
		{
			storage[i++] = *iter;
		}
	}

    template < typename Type, std::size_t Size >
    template < typename T, typename Enable >
    constexpr void Vector< Type, Size >::push_back(T&& arg) noexcept 
    {
        storage[numElements++] = std::forward< T >(arg);
    }

    template < typename Type, std::size_t Size >
    constexpr void Vector< Type, Size >::pop_back(void) noexcept
    {
        --numElements;
    }

    template < typename Type, std::size_t Size >
    template < typename... T, typename Enable >
    constexpr void Vector< Type, Size >::emplace_back(T&&... args) noexcept
    {
        storage[numElements++] = Type( std::forward<T>(args)... );
    }

    template < typename Type, std::size_t Size >
    constexpr Type const & Vector< Type, Size >::front(void) const noexcept
    {
        return storage[numElements - 1];
    }

    template < typename Type, std::size_t Size >
    constexpr typename Vector<Type, Size>::size_type Vector<Type, Size>::size(void) const noexcept
    {
        return numElements;
    }
    template < typename Type, std::size_t Size >
    constexpr bool Vector<Type, Size>::empty(void) const noexcept
    {
        return numElements == 0;
    }
    template < typename Type, std::size_t Size >
    constexpr auto Vector<Type, Size>::begin(void) const noexcept
    {
        return std::begin(storage);
    }
    template < typename Type, std::size_t Size >
    constexpr auto Vector<Type, Size>::end(void) const noexcept
    {
        return std::begin(storage) + numElements;
    }
};

#endif