#include "Waypoint.h"

#include <sstream>

#include "utility/logging/logging.h"

Waypoint::Waypoint(const Coordinate& coordinate, const std::vector<Acceleration>& accelerations)
	: m_coordinate(coordinate)
	, m_accelerations(accelerations)
{
}

Waypoint::~Waypoint()
{
}

Coordinate Waypoint::getCoordinate() const
{
	return m_coordinate;
}

unsigned int Waypoint::getAccelerationCount() const
{
	return m_accelerations.size();
}

Acceleration Waypoint::getAcceleration(unsigned int index) const
{
	if(index < m_accelerations.size())
	{
		return m_accelerations[index];
	}
	else
	{
		std::stringstream message;
		message << "Index " << index << "is out of range. ";
		message << "Maximum index is " << (m_accelerations.size()-1);
		LOG_ERROR(message.str());

		return Acceleration(0, Vec3d());
	}
}

std::vector<Acceleration> Waypoint::getAccelerations() const
{
	return m_accelerations;
}