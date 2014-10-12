#ifndef WAYPOINT_H
#define WAYPOINT_H

#include "Date.h"

class Waypoint
{
public:
	Waypoint(const unsigned int time, const unsigned int longitude, const unsigned int latitude, const unsigned int altitude, const unsigned int speed);
	~Waypoint();

private:
	unsigned int m_time;

	unsigned int m_longitude;
	unsigned int m_latitude;

	unsigned int m_altitude;
	unsigned int m_speed;
};

#endif // WAYPOINT_H