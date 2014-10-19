#include "Date.h"

Date::Date(const unsigned int hour, const unsigned int minute, const unsigned int second, const unsigned int year, const unsigned int month, const unsigned int day)
	: m_hour(hour)
	, m_minute(minute)
	, m_second(second)
	, m_year(year)
	, m_month(month)
	, m_day(day)
{
}

Date::Date(const std::string& dateString)
{
	std::tuple<std::tuple<unsigned int, unsigned int, unsigned int>, std::tuple<unsigned int, unsigned int, unsigned int>> dateTime = parseDateString(dateString);

	std::tuple<unsigned int, unsigned int, unsigned int> date = std::get<0>(dateTime);
	std::tuple<unsigned int, unsigned int, unsigned int> time = std::get<1>(dateTime);

	m_year = std::get<0>(date);
	m_month = std::get<1>(date);
	m_day = std::get<2>(date);

	m_hour = std::get<0>(time);
	m_minute = std::get<1>(time);
	m_second = std::get<2>(time);
}

Date::~Date()
{
}

std::tuple<std::tuple<unsigned int, unsigned int, unsigned int>, std::tuple<unsigned int, unsigned int, unsigned int>> Date::parseDateString(const std::string& sourceString)
{
	size_t pos = sourceString.find_first_of(" ");

	unsigned int year = 0;
	unsigned int month = 0;
	unsigned int day = 0;

	unsigned int hour = 0;
	unsigned int minute = 0;
	unsigned int second = 0;

	if(pos != std::string::npos)
	{
		std::string dateString = sourceString.substr(0, pos);
		std::string timeString = sourceString.substr(pos+1);

		std::tuple<unsigned int, unsigned int, unsigned int> date = parseDate(dateString);
		std::tuple<unsigned int, unsigned int, unsigned int> time = parseTime(timeString);

		year = std::get<0>(date);
		month = std::get<1>(date);
		day = std::get<2>(date);

		hour = std::get<0>(time);
		minute = std::get<1>(time);
		second = std::get<2>(time);
	}

	return std::make_tuple(std::make_tuple(year, month, day), std::make_tuple(hour, minute, second));
}

std::tuple<unsigned int, unsigned int, unsigned int> Date::parseDate(const std::string& date)
{
	size_t pos = date.find_first_of(".");

	unsigned int year = 0;
	unsigned int month = 0;
	unsigned int day = 0;

	if(pos != std::string::npos)
	{
		std::string yearString = date.substr(0, pos);
		std::string dateString = date.substr(pos+1);

		pos = dateString.find_first_of(".");
		if(pos != std::string::npos)
		{
			std::string monthString = dateString.substr(0, pos);
			std::string dayString = dateString.substr(pos+1);

			year = std::stoi(yearString);
			month = std::stoi(monthString);
			day = std::stoi(dayString);
		}
	}

	return std::make_tuple(year, month, day);
}

std::tuple<unsigned int, unsigned int, unsigned int> Date::parseTime(const std::string& time)
{
	size_t pos = time.find_first_of(":");

	unsigned int hour = 0;
	unsigned int minute = 0;
	unsigned int second = 0;

	if(pos != std::string::npos)
	{
		std::string hourString = time.substr(0, pos);
		std::string timeString = time.substr(pos+1);

		pos = timeString.find_first_of(":");
		if(pos != std::string::npos)
		{
			std::string minuteString = timeString.substr(0, pos);
			std::string secondString = timeString.substr(pos+1);

			hour = std::stoi(hourString);
			minute = std::stoi(minuteString);
			second = std::stoi(secondString);
		}
	}

	return std::make_tuple(hour, minute, second);
}