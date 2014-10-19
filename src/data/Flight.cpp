#include "Flight.h"

Flight::Flight(const std::string& departure, const std::string& destination, const std::string& airplane, const Date& date)
	: m_departure(departure)
	, m_destination(destination)
	, m_airplane(airplane)
	, m_date(date)
{
}

Flight::~Flight()
{
}

void Flight::addWaypoint(const Waypoint& waypoint)
{
	m_waypoints.push_back(waypoint);
}

void Flight::addWaypoints(const std::vector<Waypoint>& waypoints)
{
	for(unsigned int i = 0; i < waypoints.size(); i++)
	{
		m_waypoints.push_back(waypoints[i]);
	}
}