#include "Acceleration.h"

Acceleration::Acceleration(const unsigned int time, const Vec3d acceleration)
	: m_time(time)
	, m_acceleration(acceleration)
{
}

Acceleration::~Acceleration()
{
}