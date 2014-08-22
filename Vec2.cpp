#include "Vec2.h"

Vec2::Vec2() : x(0), y(0)
{
}

Vec2::Vec2(float x, float y) : x(x), y(y)
{
}


Vec2::~Vec2()
{
}

Vec2 operator*(float a, const Vec2 & vec)
{
	Vec2 result(vec);
	result.x *= a;
	result.y *= a;
	return result;
}
