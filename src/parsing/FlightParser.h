#ifndef FLIGHT_PARSER_H
#define FLIGHT_PARSER_H

#include <memory>

#include "json/json.h"

#include "data/Acceleration.h"
#include "data/Coordinate.h"
#include "data/Date.h"
#include "data/Flight.h"
#include "data/Waypoint.h"

class FlightParser
{
public:
	static std::shared_ptr<Flight> parseFlight(const std::string& flightData);

private:
	static std::shared_ptr<Flight> parseFlight(const Json::Value& rootNode);
	static std::vector<Waypoint> parseWaypoints(const Json::Value& waypointsRoot);
	static Coordinate parseWaypointCoordinate(const Json::Value& waypoint);
	static Acceleration parseWaypointAcceleration(const Json::Value& waypoint);
};

#endif // FLIGHT_PARSER_H