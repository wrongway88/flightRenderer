#include "Flight.h"

Flight::Flight()
{
}

Flight::~Flight()
{
}

void Flight::addWaypoint(const Waypoint& waypoint)
{
	m_waypoints.push_back(waypoint);
}