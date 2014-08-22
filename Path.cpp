#include <cassert>
#include "Path.h"
#include "Game.h"

Path::Path(const Vec2 & segmentStartPoint, const Vec2 & segmentEndPoint)
{
	PathSegment firstSegment(segmentStartPoint, segmentEndPoint);
	segments.push_back(firstSegment);
	length = firstSegment.length;
}

Path::~Path()
{
}

void Path::analyzeSegment(const PathSegment & segment, const Vec2 & point, float & distanceAlongSegmentToclosestPoint, float & distanceToClosestPoint)
{
	float param = segment.computeDistanceAlongSegmentToClosestPoint(point);
	Vec2 closestPoint = segment.computePointOnSegment(param);
	float distance = (closestPoint - point).length();
}

float Path::computeParam(float minParam, const Vec2 & point)
{
	assert(minParam >= 0);
	assert(segments.size() >= 1);

	// Locate first segement to consider.
	float minDistanceToGo = minParam;
	float distanceOfDiscardedSegments = 0;
	unsigned int i = 0;
	while (i < segments.size() && minDistanceToGo >= segments[i].length)
	{
		minDistanceToGo -= segments[i].length;
		distanceOfDiscardedSegments += segments[i].length;
		++i;
	}
	if (i >= segments.size())
	{
		Game::fatalError("minParam exceeds length of path in Path::computeParam().");	
	}

	// Look at current segment.
	unsigned int closestSegment = i;
	float distanceAlongSegmentToClosestPoint;
	float distanceToClosestPoint;
	segments[i].analyzePoint(point, minDistanceToGo, distanceAlongSegmentToClosestPoint, distanceToClosestPoint);

	// Go to next segment if closer.
	++i;
	while (i < segments.size())
	{
		float distanceAlongSegment;
		float distance;
		segments[i].analyzePoint(point, 0, distanceAlongSegment, distance);
		if (distance < distanceToClosestPoint)
		{
			distanceOfDiscardedSegments += segments[i-1].length;
			distanceAlongSegmentToClosestPoint = distanceAlongSegment;
			distanceToClosestPoint = distance;
			closestSegment = i;
			++i;
		}
		else
		{
			break;
		}
	}
	return distanceOfDiscardedSegments + distanceAlongSegmentToClosestPoint;
}

Vec2 Path::computePosition(float param)
{
	assert(param >= 0);
	for (unsigned int i = 0; i < segments.size(); ++i)
	{
		if (param < segments[i].length)
		{
			// The position is in the ith segment.
			return segments[i].computePointOnSegment(param);
		}
		param -= segments[i].length;
	}
	Game::fatalError("param exceeds length of path in Path::computePosition().");	
	return Vec2();
}

void Path::createNextPathSegment(const Vec2 & segmentEndPoint)
{
	PathSegment segment(segments.back().end, segmentEndPoint);
	segments.push_back(segment);
	length += segment.length;
}

