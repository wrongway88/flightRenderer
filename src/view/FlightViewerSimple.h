#ifndef FLIGHT_VIEWER_H
#define FLIGHT_VIEWER_H

#include <memory>

#include "IFlightViewer.h"

#include "data/Flight.h"

class FlightViewerSimple : public IFlightViewer
{
public:
	FlightViewerSimple(const std::shared_ptr<Flight>& flight);
	~FlightViewerSimple();

	virtual void draw() const;

private:
	void drawAcceleration(const Vec3d& pos0, const Vec3d& pos1, const std::vector<Acceleration>& accelerations, const Vec3d& baseAcceleration) const;
};

#endif // FLIGHT_VIEWER_H