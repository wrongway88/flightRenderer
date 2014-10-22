#include "FlightViewerSimple.h"

#include "cinder/gl/gl.h"

#include "utility/logging/logging.h"

FlightViewerSimple::FlightViewerSimple(const std::shared_ptr<Flight>& flight)
	: IFlightViewer(flight)
{}

FlightViewerSimple::~FlightViewerSimple()
{
}

void FlightViewerSimple::draw() const
{
	float scaleFactor = 0.4;

	Vec3d offset;

	ci::gl::begin(GL_LINE_STRIP);

	for(unsigned int i = 0; i < m_flight->getWaypointCount(); i++)
	{
		ci::gl::color(1.0f, 0.5f, 0.25f);

		Vec3d vertex = m_flight->getWaypoint(i).getCoordinate().getCartesianCoordinates();

		if(vertex.getLengthSquared() <= 0.0)
		{
			continue;
		}

		if(i == 0)
		{
			offset = vertex;
		}

		vertex -= offset;
		vertex *= scaleFactor;

		//LOG_INFO((vertex).toString());

		ci::gl::vertex(vertex.x, vertex.y, vertex.z);

		//LOG_INFO((vertex*0.1).toString());
	}

	ci::gl::end();

	Vec3d previousPosition;
	Vec3d baseAcceleration;

	for(unsigned int i = 0; i < m_flight->getWaypointCount(); i++)
	{
		Vec3d vertex = m_flight->getWaypoint(i).getCoordinate().getCartesianCoordinates();

		if(i == 0)
		{
			offset = vertex;
			baseAcceleration = m_flight->getWaypoint(i).getAcceleration(0).getAcceleration();
		}

		vertex -= offset;
		vertex *= scaleFactor;

		//LOG_INFO((vertex).toString());

		drawAcceleration(previousPosition, vertex, m_flight->getWaypoint(i).getAccelerations(), baseAcceleration);

		previousPosition = vertex;
	}
}

void FlightViewerSimple::drawAcceleration(const Vec3d& pos0, const Vec3d& pos1, const std::vector<Acceleration>& accelerations, const Vec3d& baseAcceleration) const
{
	Vec3d direction = (pos1 - pos0).normalized();
	float delta = (pos1 - pos0).getLength() / (float)accelerations.size();

	for(unsigned int i = 0; i < accelerations.size(); i++)
	{
		Vec3d pos = pos0 + (direction * (delta * i));
		Vec3d vec = pos + ((accelerations[i].getAcceleration() - baseAcceleration) * 5.0);

		ci::gl::begin(GL_LINE_STRIP);
		ci::gl::color(1.0f, 0.0f, 0.25f);
			ci::gl::vertex(pos.x, pos.y, pos.z);
			ci::gl::vertex(vec.x, vec.y, vec.z);
		ci::gl::end();
	}
}