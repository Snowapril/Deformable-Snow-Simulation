#ifndef UTILITY_H
#define UTILITY_H

namespace ToonResourceParser
{
	template <typename Type1, typename Type2>
	class Pair
	{
	public:
		using FirstType  = typename Type1;
		using SecondType = typename Type2;

		template <typename _Ty1, typename _Ty2>
		constexpr explicit Pair(_Ty1&& first, _Ty2&& second) noexcept : first(std::forward<_Ty1>(first)), second(std::forward<_Ty2>(second)) {};

	public:
		FirstType  first;
		SecondType second;
	};

	template <typename...>
	using void_t = void;

	template <typename Type, typename = void>
	struct is_iterator_type : std::false_type {};

	template <typename Type>
	struct is_iterator_type < Type, void_t<
											decltype(++std::declval<Type&>()),
											decltype(*std::declval<Type&>()),
											decltype(std::declval<Type&>() == std::declval<Type&>)
										  > 
							> : std::true_type {};
	template <typename Type>
	using is_iterator_t = typename is_iterator_type<Type>::type;
};

#endif