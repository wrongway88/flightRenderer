#include "utility/logging/ConsoleLogger.h"

#include <iostream>
#include <Windows.h>

const unsigned int ConsoleLogger::colorStandard = 15; // white
const unsigned int ConsoleLogger::colorInfo = 10; // green
const unsigned int ConsoleLogger::colorWarning = 14; // yellow
const unsigned int ConsoleLogger::colorError = 12; // red

ConsoleLogger::ConsoleLogger()
	: Logger("ConsoleLogger")
{
}

ConsoleLogger::~ConsoleLogger()
{
}

void ConsoleLogger::logInfo(const LogMessage& message)
{
	logMessage(LOG_TYPE::LOG_INFO, message);
}

void ConsoleLogger::logWarning(const LogMessage& message)
{
	logMessage(LOG_TYPE::LOG_WARNING, message);
}

void ConsoleLogger::logError(const LogMessage& message)
{
	logMessage(LOG_TYPE::LOG_ERROR, message);
}

void ConsoleLogger::logMessage(LOG_TYPE type, const LogMessage& message)
{
	HANDLE consoleHandle;
	consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(consoleHandle, colorStandard);
	std::cout
		<< message.getTimeString("%H:%M:%S") << " | "
		<< message.getFileName() << ':' << message.line << ' ' << message.functionName << "() | ";

	switch(type)
	{
	case LOG_TYPE::LOG_INFO:
		SetConsoleTextAttribute(consoleHandle, colorInfo);
		std::cout << "INFO";
		break;
	case LOG_TYPE::LOG_WARNING:
		SetConsoleTextAttribute(consoleHandle, colorWarning);
		std::cout << "WARNING";
		break;
	case LOG_TYPE::LOG_ERROR:
		SetConsoleTextAttribute(consoleHandle, colorError);
		std::cout << "ERROR";
		break;
	default:
		SetConsoleTextAttribute(consoleHandle, colorStandard);
		break;
	}

	SetConsoleTextAttribute(consoleHandle, colorStandard);
	std::cout
		<< ": " << message.message
		<< std::endl;
}
