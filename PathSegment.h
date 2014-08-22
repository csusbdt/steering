#pragma once

#include "Vec2.h"

struct PathSegment
{
	PathSegment(const Vec2 & start, const Vec2 & end);
	virtual ~PathSegment() { }

	void operator=(const PathSegment & segment);
	Vec2 computePointOnSegment(float distanceAlongSegment) const;
	float computeDistanceAlongSegmentToClosestPoint(const Vec2 & point) const;
	void analyzePoint(const Vec2 & point, const float & minDistanceAlongSegment, float & distanceAlongSegmentToClosestPoint, float & distanceToClosestPoint) const;

	Vec2 start;
	Vec2 end;
	float length;
};
