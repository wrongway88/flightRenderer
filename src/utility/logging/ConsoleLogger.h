#ifndef CONSOLE_LOGGER_H
#define CONSOLE_LOGGER_H

#include "utility/logging/Logger.h"
#include "utility/logging/LogMessage.h"

class ConsoleLogger: public Logger
{
public:
	ConsoleLogger();
	~ConsoleLogger();

	virtual void logInfo(const LogMessage& message);
	virtual void logWarning(const LogMessage& message);
	virtual void logError(const LogMessage& message);

private:
	enum LOG_TYPE
	{
		LOG_INFO = 0,
		LOG_WARNING,
		LOG_ERROR
	};

	void logMessage(LOG_TYPE type, const LogMessage& message);

	const static unsigned int colorStandard;
	const static unsigned int colorInfo;
	const static unsigned int colorWarning;
	const static unsigned int colorError;
};

#endif // CONSOLE_LOGGER_H
