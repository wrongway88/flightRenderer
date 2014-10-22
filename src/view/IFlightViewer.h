#ifndef I_FLIGHT_VIEWER_H
#define I_FLIGHT_VIEWER_H

#include <memory>

#include "data/Flight.h"

class IFlightViewer
{
public:
	IFlightViewer(const std::shared_ptr<Flight>& flight);
	~IFlightViewer();

	virtual void draw() const = 0;

protected:
	std::shared_ptr<Flight> m_flight;
};

#endif // I_FLIGHT_VIEWER_H