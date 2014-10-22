#include "Acceleration.h"

Acceleration::Acceleration(const unsigned int time, const Vec3d acceleration)
	: m_time(time)
	, m_acceleration(acceleration)
{
}

Acceleration::~Acceleration()
{
}

unsigned int Acceleration::getTime() const
{
	return m_time;
}

Vec3d Acceleration::getAcceleration() const
{
	return m_acceleration;
}