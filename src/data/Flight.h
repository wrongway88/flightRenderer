#ifndef FLIGHT_H
#define FLIGHT_H

#include <vector>

#include "Waypoint.h"

class Flight
{
public:
	Flight();
	~Flight();

	void addWaypoint(const Waypoint& waypoint);

private:
	std::vector<Waypoint> m_waypoints;
};

#endif // FLIGHT_H