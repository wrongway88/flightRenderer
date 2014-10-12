#ifndef FLIGHT_FILE_PARSER_H
#define FLIGHT_FILE_PARSER_H

#include <string>

class FlightFileParser
{
public:
	static void parseFile(const std::string& filePath);
};

#endif // FLIGHT_FILE_PARSER_H