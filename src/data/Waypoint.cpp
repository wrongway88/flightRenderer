#include "Waypoint.h"

Waypoint::Waypoint(const Coordinate& coordinate, const std::vector<Acceleration>& accelerations)
	: m_coordinate(coordinate)
	, m_accelerations(accelerations)
{
}

Waypoint::~Waypoint()
{
}