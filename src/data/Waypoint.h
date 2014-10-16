#ifndef WAYPOINT_H
#define WAYPOINT_H

#include "Date.h"

class Waypoint
{
public:
	Waypoint(const unsigned int time, const double longitude, const double latitude, const double altitude, const double speed);
	~Waypoint();

private:
	unsigned int m_time;

	double m_longitude;
	double m_latitude;

	double m_altitude;
	double m_speed;
};

#endif // WAYPOINT_H