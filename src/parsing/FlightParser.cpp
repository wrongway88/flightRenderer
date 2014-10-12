#include "FlightParser.h"

#include "utility/logging/logging.h"

void FlightParser::parseFlight(const std::string& flightData)
{
	LOG_INFO("Start flight parsing");

	Json::Value rootNode;
	Json::Reader reader;

	if(reader.parse(flightData, rootNode))
	{
		parseFlight(rootNode);
	}
	else
	{
		LOG_ERROR("Failed to parse flight.");
	}

	LOG_INFO("End flight parsing");
}

void FlightParser::parseFlight(const Json::Value& rootNode)
{
	std::stringstream message;
	message << "Root has size of ";
	message << rootNode.size();
	LOG_INFO(message.str());

	std::string departure = rootNode["departure"].asString();
	std::string destination = rootNode["destination"].asString();
	std::string airplane = rootNode["airplane"].asString();
	std::string date = rootNode["date"].asString();

	parseWaypoints(rootNode["waypoints"]);
}

void FlightParser::parseWaypoints(const Json::Value& waypointsRoot)
{
	std::stringstream message;
	message << "Waypoints has size of ";
	message << waypointsRoot.size();
	LOG_INFO(message.str());
}