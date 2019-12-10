#pragma once

#include "Core.h"
#include <type_traits>
#include <utility>

namespace BE
{
	template <class T1,class T2>
	struct BS_API Pair
	{
	public:
		T1 first;
		T2 second;

		constexpr Pair()
			: first(), second() {}

		constexpr Pair(const Pair& other)
			: first(other.first), second(other.second) {}

		constexpr Pair(Pair&& other)
			: first(std::move(other.first)), second(std::move(other.second)) {}

		constexpr Pair(const T1& x, const T2& y)
			: first(x), second(y) {}

		constexpr Pair(const T1&& x, const T2&& y)
			: first(std::move(x)), second(std::move(y)) {}

		template <class U1, class U2>
		constexpr Pair(U1&& x, U2&& y)
			: first(std::forward<U1>(x)), std::forward<U2>(y)) {}

		template <class U1, class U2>
		constexpr Pair(const Pair<U1, U2>& other)
			: first(other.first), second(other.second) {}

		template <class U1, class U2>
		constexpr Pair(Pair<U1, U2>&& other) 
			: first(std::move(other.first)), second(std::move(other.second)) {}

		template <class U1, class U2>
		constexpr Pair& operator=(const Pair<U1, U2>& other)
		{
			first = other.first;
			first = other.second;
		}

		template <class U1, class U2>
		constexpr Pair& operator=(Pair<U1, U2>&& other)
		{
			first = std::move(other.first);
			second = std::move(other.second);
		}

		constexpr void Swap(Pair& other) noexcept
			(
				noexcept(Swap(first, other.first)) &&
				noexcept(Swap(second, other.second))
			)
		{
			Swap(first, other.first);
			Swap(second, other.second);
		}
	};

	template <class T1, class T2>
	inline constexpr Pair<T1, T2> MakePair(T1&& t, T2&& u)
	{
		return Pair<T1, T2>(std::forward<T1>(t), std::forward<T2>(u));
	}

	template <class T1, class T2>
	constexpr bool operator==(const Pair<T1, T2>& lhs, const Pair<T1, T2>& rhs)
	{
		return lhs.first == rhs.first && lhs.second == rhs.second;
	}

	template <class T1, class T2>
	constexpr bool operator!=(const Pair<T1, T2>& lhs, const Pair<T1, T2>& rhs)
	{
		return !(lhs == rhs);
	}

	template <class T1, class T2>
	constexpr bool operator<(const Pair<T1, T2>& lhs, const Pair<T1, T2>& rhs)
	{
		if (lhs.first != rhs.first)
			return lhs.first < rhs.first;

		return lhs.second < rhs.second;
	}

	template <class T1, class T2>
	constexpr bool operator>(const Pair<T1, T2>& lhs, const Pair<T1, T2>& rhs)
	{
		return rhs < lhs;
	}

	template <class T1, class T2>
	constexpr bool operator<=(const Pair<T1, T2>& lhs, const Pair<T1, T2>& rhs)
	{
		return !(rhs < lhs);
	}

	template <class T1, class T2>
	constexpr bool operator>=(const Pair<T1, T2>& lhs, const Pair<T1, T2>& rhs)
	{
		return !(lhs < rhs)
	}

	template <class T1, class T2>
	constexpr void Swap(Pair<T1, T2>& x, Pair<T1, T2>& y) noexcept(noexcept(x.Swap(y)))
	{
		x.Swap(y);
	}

	template <SizeType I, class T1, class T2>
	inline constexpr decltype(auto)& get(Pair<T1, T2>& p) noexcept
	{
		if constexpr (I == 0) return p.first;
		if (I == 1) return p.second;
		static_assert(false);
	}

	template <SizeType I, class T1, class T2>
	inline constexpr decltype(auto) && get(Pair<T1, T2>&& p) noexcept
	{
		if constexpr (I == 0) return std::move(p.first);
		if (I == 1) return std::move(p.second);
		static_assert(false);
	}

	template <SizeType I, class T1, class T2>
	inline constexpr const decltype(auto)& get(const Pair<T1, T2>& p) noexcept
	{
		if constexpr (I == 0) return p.first;
		if (I == 1) return p.second;
		static_assert(false);
	}

	template <SizeType I, class T1, class T2>
	inline constexpr const decltype(auto) && get(const Pair<T1, T2>&& p) noexcept
	{
		if constexpr (I == 0) return std::move(p.first);
		if (I == 1) return std::move(p.second);
		static_assert(false);
	}

	template <class T1, class T2>
	inline constexpr decltype(auto)& get(Pair<T1, T2>& p) noexcept
	{
		return p.first;
	}

	template <class T2, class T1>
	inline constexpr decltype(auto)& get(Pair<T1, T2>& p) noexcept
	{
		return p.second;
	}

	template <class T1, class T2>
	inline constexpr decltype(auto)&& get(Pair<T1, T2>& p) noexcept
	{
		return p.first;
	}

	template <class T2, class T1>
	inline constexpr decltype(auto)&& get(Pair<T1, T2>& p) noexcept
	{
		return p.second;
	}

	template <class T1, class T2>
	inline constexpr const decltype(auto)& get(Pair<T1, T2>& p) noexcept
	{
		return p.first;
	}

	template <class T2, class T1>
	inline constexpr const decltype(auto)& get(Pair<T1, T2>& p) noexcept
	{
		return p.second;
	}

	template <class T1, class T2>
	inline constexpr const decltype(auto)&& get(Pair<T1, T2>& p) noexcept
	{
		return p.first;
	}

	template <class T2, class T1>
	inline constexpr const decltype(auto)&& get(Pair<T1, T2>& p) noexcept
	{
		return p.second;
	}
}