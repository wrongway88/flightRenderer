#ifndef FLIGHT_FILE_PARSER_H
#define FLIGHT_FILE_PARSER_H

#include <string>
#include <memory>

#include "data/Flight.h"

class FlightFileParser
{
public:
	static std::shared_ptr<Flight> parseFile(const std::string& filePath);
};

#endif // FLIGHT_FILE_PARSER_H