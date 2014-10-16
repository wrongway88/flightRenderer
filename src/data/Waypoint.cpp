#include "Waypoint.h"

Waypoint::Waypoint(const unsigned int time, const double longitude, const double latitude, const double altitude, const double speed)
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