#ifndef COORDINATE_H
#define COORDINATE_H

#include "Date.h"

class Coordinate
{
public:
	Coordinate();
	Coordinate(const unsigned int time, const double longitude, const double latitude, const double altitude, const double speed);
	~Coordinate();

	bool initialized() const;

private:
	bool m_initialized;

	unsigned int m_time;

	double m_longitude;
	double m_latitude;

	double m_altitude;
	double m_speed;
};

#endif // COORDINATE_H