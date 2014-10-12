#include "Waypoint.h"

Waypoint::Waypoint(const unsigned int time, const unsigned int longitude, const unsigned int latitude, const unsigned int altitude, const unsigned int speed)
	: m_time(time)
	, m_longitude(longitude)
	, m_latitude(latitude)
	, m_altitude(altitude)
	, m_speed(speed)
{
}

Waypoint::~Waypoint()
{
}