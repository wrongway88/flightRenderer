#include "Coordinate.h"

Coordinate::Coordinate()
	: m_initialized(false)
	, m_time(0)
	, m_longitude(0.0)
	, m_latitude(0.0)
	, m_altitude(0.0)
	, m_speed(0.0)
{
}

Coordinate::Coordinate(const unsigned int time, const double longitude, const double latitude, const double altitude, const double speed)
	: m_initialized(true)
	, m_time(time)
	, m_longitude(longitude)
	, m_latitude(latitude)
	, m_altitude(altitude)
	, m_speed(speed)
{
}

Coordinate::~Coordinate()
{
}

bool Coordinate::initialized() const
{
	return m_initialized;
}