#ifndef FLIGHT_H
#define FLIGHT_H

#include <vector>

#include "Date.h"
#include "Waypoint.h"

class Flight
{
public:
	Flight(const std::string& departure, const std::string& destination, const std::string& airplane, const Date& date);
	~Flight();

	void addWaypoint(const Waypoint& waypoint);
	void addWaypoints(const std::vector<Waypoint>& waypoints);

	unsigned int getWaypointCount() const;

	Waypoint getWaypoint(const unsigned int index) const;

private:
	std::string m_departure;
	std::string m_destination;
	std::string m_airplane;
	Date m_date;

	std::vector<Waypoint> m_waypoints;
};

#endif // FLIGHT_H