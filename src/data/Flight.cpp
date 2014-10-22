#include "Flight.h"

#include <sstream>

#include "utility/logging/logging.h"

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

unsigned int Flight::getWaypointCount() const
{
	return m_waypoints.size();
}

Waypoint Flight::getWaypoint(const unsigned int index) const
{
	if(index < m_waypoints.size())
	{
		return m_waypoints[index];
	}
	else
	{
		std::stringstream message;
		message << "Index " << index << "is out of range. ";
		message << "Maximum index is " << (m_waypoints.size()-1);
		LOG_ERROR(message.str());

		return Waypoint(Coordinate(), std::vector<Acceleration>());
	}
}