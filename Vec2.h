#pragma once

#include <cmath>

class Vec2
{
public:
	Vec2();
	Vec2(const Vec2 & vec) : x(vec.x), y(vec.y) { }
	Vec2(float x, float y);
	~Vec2();

	float x;
	float y;

	void operator=(const Vec2 & vec)
	{
		x = vec.x;
		y = vec.y;
	}

	void operator*=(float a)
	{
		x *= a;
		y *= a;
	}

	Vec2 operator*(float a) const
	{
		Vec2 vec(*this);
		vec.x *= a;
		vec.y *= a;
		return vec;
	}

	Vec2 operator/(float a) const
	{
		Vec2 vec(*this);
		vec.x /= a;
		vec.y /= a;
		return vec;
	}

	void operator+=(const Vec2 & vec)
	{
		x += vec.x;
		y += vec.y;
	}

	Vec2 operator+(const Vec2 & v) const
	{
		Vec2 vec(*this);
		vec.x += v.x;
		vec.y += v.y;
		return vec;
	}

	Vec2 operator-(const Vec2 & v) const
	{
		Vec2 vec(*this);
		vec.x -= v.x;
		vec.y -= v.y;
		return vec;
	}

	float length()
	{
		if (x > 0.0001f || x < -0.0001f || y > 0.0001f || y < -0.0001f)
		{
			return sqrtf(x * x + y * y);
		}
		else
		{
		   return 0;
		}
	}

	void normalize()
	{
		float len = length();
		if (len > 0.00001)
		{
			x = x / len;
			y = y / len;
		}
	}

	float dot(const Vec2 & vec)
	{
		return x * vec.x + y * vec.y;
	}
};

Vec2 operator*(float a, const Vec2 & vec);
