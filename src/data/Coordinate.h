#ifndef COORDINATE_H
#define COORDINATE_H

#include "utility/math/Vector3.h"

#include "Date.h"

class Coordinate
{
public:
	Coordinate();
	Coordinate(const unsigned int time, const double longitude, const double latitude, const double altitude, const double speed);
	~Coordinate();

	bool initialized() const;

	double getLongitude() const;
	double getLatitude() const;
	double getAltitude() const;
	double getSpeed() const;

	Vec3d getCartesianCoordinates() const;

	static Vec3d calculateCartesianCoordinates(double latitude, double longitude, double altitude);

private:
	bool m_initialized;

	unsigned int m_time;

	double m_longitude;
	double m_latitude;

	double m_altitude;
	double m_speed;

	Vec3d m_cartesianCoordinates;
};

#endif // COORDINATE_H