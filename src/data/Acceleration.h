#ifndef ACCELERATION_H
#define ACCELERATION_H

#include "utility/math/Vector3.h"

class Acceleration
{
public:
	Acceleration(const unsigned int time, const Vec3d acceleration);
	~Acceleration();

private:
	unsigned int m_time;
	Vec3d m_acceleration;
};

#endif // ACCELERATION_H