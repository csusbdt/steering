#pragma once

#include <vector>
#include "PathSegment.h"
#include "Vec2.h"

/**
 * This path class represents a connected sequence of straight line segments.
 * In this class, the term "param" refers to the distance traveled along the path.
 */
class Path
{
public:
	/**
	 * Path constructor takes the start and end points of the first segment.
	 */
	Path(const Vec2 & segmentStartPoint, const Vec2 & segmentEndPoint);

	virtual ~Path();

	/**
	 * Compute distance along path to the point on the path that is nearest to 
	 * the given point.  Omit the initial minParam length of the path.
	 */
	float computeParam(float minParam, const Vec2 & point);

	Vec2 computePosition(float param);
	void createNextPathSegment(const Vec2 & endPoint);

	std::vector<PathSegment> segments;

	float length;

private:
	void analyzeSegment(const PathSegment & segment, const Vec2 & point, float & distanceAlongSegmentToclosestPoint, float & distanceToClosestPoint);
};
