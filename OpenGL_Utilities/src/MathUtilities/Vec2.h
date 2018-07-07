#pragma once

#include <cmath>
#include <utility>
#include "HashUtilities.h"

template<typename T>
class Vec2_
{
public:
	Vec2_() = default;
	Vec2_(T x_in, T y_in)
		:
		x(x_in),
		y(y_in)
	{}
	template<typename S>
	explicit Vec2_(const Vec2_<S>& src)
		:
		x((T)src.x),
		y((T)src.y)
	{}
	Vec2_ operator+(const Vec2_& rhs) const
	{
		return Vec2_(x + rhs.x, y + rhs.y);
	}
	Vec2_& operator+=(const Vec2_& rhs)
	{
		return *this = *this + rhs;
	}
	bool operator==(Vec2_ rhs) const
	{
		return (this->x == rhs.x && this->y == rhs.y) ? true : false;
	}
	bool operator!=(Vec2_ rhs) const
	{
		return (this->x != rhs.x || this->y != rhs.y) ? true : false;
	}
	Vec2_ operator*(T rhs) const
	{
		return Vec2_(x * rhs, y * rhs);
	}
	Vec2_& operator*=(T rhs)
	{
		return *this = *this * rhs;
	}
	Vec2_ operator-(const Vec2_& rhs) const
	{
		return Vec2_(x - rhs.x, y - rhs.y);
	}
	Vec2_& operator-=(const Vec2_& rhs)
	{
		return *this = *this - rhs;
	}
	T GetLength() const
	{
		return (T)std::sqrt(GetLengthSq());
	}
	T GetLengthSq() const
	{
		return x * x + y * y;
	}
	Vec2_& Normalize()
	{
		return *this = GetNormalized();
	}
	Vec2_ GetNormalized() const
	{
		const T len = GetLength();
		if (len != (T)0)
		{
			return *this * ((T)1 / len);
		}
		return *this;
	}
	T GetDistance(Vec2_ v)
	{
		return sqrt(pow((v.x - x), 2) + pow((v.y - y), 2));
	}

	T x;
	T y;
};

typedef Vec2_<float> Vec2;
typedef Vec2_<int> Vei2;

namespace std
{
	template <> struct hash<Vei2>
	{
		size_t operator()(const Vei2& v) const
		{
			size_t seed = 0;
			hash_combine(seed, v.x);
			hash_combine(seed, v.y);

			return seed;
		}
	};

	template <> struct hash<Vec2>
	{
		size_t operator()(const Vec2& v) const
		{
			size_t seed = 0;
			hash_combine(seed, v.x);
			hash_combine(seed, v.y);

			return seed;
		}
	};
}

