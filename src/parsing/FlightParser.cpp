#include "FlightParser.h"

#include "utility/logging/logging.h"
#include "utility/math/Vector3.h"

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
	std::string departure = rootNode["departure"].asString();
	std::string destination = rootNode["destination"].asString();
	std::string airplane = rootNode["airplane"].asString();
	std::string date = rootNode["date"].asString();

	std::stringstream message;
	message << "Parsing flight: ";
	message << departure << ", ";
	message << destination << ", ";
	message << airplane << ", ";
	message << date;
	LOG_INFO(message.str());

	parseWaypoints(rootNode["waypoints"]);
}

void FlightParser::parseWaypoints(const Json::Value& waypointsRoot)
{
	std::stringstream message;
	message << "Waypoints has size of ";
	message << waypointsRoot.size();
	LOG_INFO(message.str());

	for(unsigned int i = 0; i < waypointsRoot.size(); i++)
	{
		std::stringstream wpMessage;
		wpMessage << "waypoint size ";
		wpMessage << waypointsRoot[i].size();
		LOG_INFO(wpMessage.str());
		
		if(waypointsRoot[i].size() == 5)
		{
			parseWaypointCoordinate(waypointsRoot[i]);
		}
		else
		{
			parseWaypointAcceleration(waypointsRoot[i]);
		}
	}
}

Waypoint FlightParser::parseWaypointCoordinate(const Json::Value& waypoint)
{
	std::string sT = waypoint["t"].asString();
	std::string sLat = waypoint["lat"].asString();
	std::string sLong = waypoint["long"].asString();
	std::string sAlt = waypoint["alt"].asString();
	std::string sSpeed = waypoint["speed"].asString();

	int t = std::stoi(sT);
	double lat = std::stod(sLat);
	double dLong = std::stod(sLong);
	double alt = std::stod(sAlt);
	double speed = std::stod(sSpeed);

	return Waypoint(t, dLong, lat, alt, speed);
}

Acceleration FlightParser::parseWaypointAcceleration(const Json::Value& waypoint)
{
	std::string sT = waypoint["t"].asString();
	std::string sX = waypoint["x"].asString();
	std::string sY = waypoint["y"].asString();
	std::string sZ = waypoint["z"].asString();

	int t = std::stoi(sT);
	double x = std::stod(sX);
	double y = std::stod(sY);
	double z = std::stod(sZ);

	return Acceleration(t, Vec3d(x, y, z));
}