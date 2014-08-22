#include "PathSegment.h"

void PathSegment::operator=(const PathSegment & segment)
{
	this->start = segment.start;
	this->end = segment.end;
	this->length = segment.length;
}

PathSegment::PathSegment(const Vec2 & start, const Vec2 & end) : start(start), end(end)
{ 
	length = (end - start).length();
}

void PathSegment::analyzePoint(const Vec2 & point, const float & minDistanceAlongSegment, float & distanceAlongSegmentToClosestPoint, float & distanceToClosestPoint) const
{
	distanceAlongSegmentToClosestPoint = computeDistanceAlongSegmentToClosestPoint(point);
	if (distanceAlongSegmentToClosestPoint < minDistanceAlongSegment)
	{
		distanceAlongSegmentToClosestPoint = minDistanceAlongSegment;
	}
	Vec2 closestPoint = computePointOnSegment(distanceAlongSegmentToClosestPoint);
	distanceToClosestPoint = (closestPoint - point).length();
}

Vec2 PathSegment::computePointOnSegment(float distanceAlongSegment) const
{
	float endWeight = distanceAlongSegment / length;
	float startWeight = 1 - endWeight;
	return startWeight * start + endWeight * end; 
}

float PathSegment::computeDistanceAlongSegmentToClosestPoint(const Vec2 & point) const
{
	// Case 1: point is closest to start.
	if ((point - start).dot(end - start) < 0)
	{
		return 0;
	}

	// Case 2: point is closest to end.
	if ((point - end).dot(start - end) < 0)
	{
		//float x = (point - end).dot(start - end);
		return length;
	}

	// Case 3: point is closest to point between start and end.
	return (end - start).dot(point - start) / length;
}
