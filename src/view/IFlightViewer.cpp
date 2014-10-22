#include "IFlightViewer.h"

IFlightViewer::IFlightViewer(const std::shared_ptr<Flight>& flight)
	: m_flight(flight)
{
}

IFlightViewer::~IFlightViewer()
{
}