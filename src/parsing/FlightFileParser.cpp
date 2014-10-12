#include "FlightFileParser.h"

#include <fstream>
#include <sstream>

#include "utility/logging/logging.h"

#include "parsing/FlightParser.h"

void FlightFileParser::parseFile(const std::string& filePath)
{
	LOG_INFO("Start parsing fila at " + filePath);

	std::ifstream file;
	file.open(filePath);

	if(file.is_open())
	{
		std::string line;
		std::string fileContent;

		while(std::getline(file, line))
		{
			fileContent += line;
		}

		file.close();

		if(fileContent.length() > 0)
		{
			FlightParser::parseFlight(fileContent);
		}
		else
		{
			LOG_WARNING("File at " + filePath + " appears to be empty.");
		}
	}
	else
	{
		std::stringstream message;
		message << "Failed to open file at path ";
		message << filePath;
		LOG_ERROR(message.str());
	}

	LOG_INFO("Finished parsing fila at " + filePath);
}