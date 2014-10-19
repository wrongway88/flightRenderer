#ifndef WAYPOINT_H
#define WAYPOINT_H

#include <vector>

#include "Acceleration.h"
#include "Coordinate.h"

class Waypoint
{
public:
	Waypoint(const Coordinate& coordinate, const std::vector<Acceleration>& accelerations);
	~Waypoint();

private:
	Coordinate m_coordinate;
	std::vector<Acceleration> m_accelerations;
};

#endif // WAYPOINT_H