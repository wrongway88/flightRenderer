#ifndef FLIGHT_PARSER_H
#define FLIGHT_PARSER_H

#include "json/json.h"

class FlightParser
{
public:
	static void parseFlight(const std::string& flightData);

private:
	static void parseFlight(const Json::Value& rootNode);
	static void parseWaypoints(const Json::Value& waypointsRoot);
};

#endif // FLIGHT_PARSER_H