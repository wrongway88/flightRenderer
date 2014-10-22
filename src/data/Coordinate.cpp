#include "Coordinate.h"

#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif

#include <math.h>

Coordinate::Coordinate()
	: m_initialized(false)
	, m_time(0)
	, m_longitude(0.0)
	, m_latitude(0.0)
	, m_altitude(0.0)
	, m_speed(0.0)
	, m_cartesianCoordinates(0.0, 0.0, 0.0)
{
}

Coordinate::Coordinate(const unsigned int time, const double longitude, const double latitude, const double altitude, const double speed)
	: m_initialized(true)
	, m_time(time)
	, m_longitude(longitude)
	, m_latitude(latitude)
	, m_altitude(altitude)
	, m_speed(speed)
	, m_cartesianCoordinates(calculateCartesianCoordinates(latitude, longitude, altitude))
{
}

Coordinate::~Coordinate()
{
}

bool Coordinate::initialized() const
{
	return m_initialized;
}

double Coordinate::getLongitude() const
{
	return m_longitude;
}

double Coordinate::getLatitude() const
{
	return m_latitude;
}

double Coordinate::getAltitude() const
{
	return m_altitude;
}

double Coordinate::getSpeed() const
{
	return m_speed;
}

Vec3d Coordinate::getCartesianCoordinates() const
{
	return m_cartesianCoordinates;
}

Vec3d Coordinate::calculateCartesianCoordinates(double latitude, double longitude, double altitude)
{
	Vec3d result;

	/**
	 * @source http://stackoverflow.com/questions/8981943/lat-long-to-x-y-z-position-in-js-not-working
	 * hm, not working?
	 */

	double cosLat = std::cos(latitude * M_PI / 180.0);
	double sinLat = std::sin(latitude * M_PI / 180.0);
	double cosLong = std::cos(longitude * M_PI / 180.0);
	double sinLong = std::cos(longitude * M_PI / 180.0);
	double rad = 6378137.0;
	double f = 1.0 / 298.257224;
	double C = 1.0 / std::sqrt(cosLat * cosLat + (1.0 - f) * (1.0 - f) * sinLat * sinLat);
	double S = (1.0 - f) * (1.0 - f) * C;

	result.x = (rad * C + altitude) * cosLat * cosLong;
	result.y = (rad * C + altitude) * cosLat * sinLong;
	result.z = (rad * S + altitude) * sinLat;

	/*result.x = latitude;
	result.y = longitude;
	result.z = altitude;*/

	return result;
}