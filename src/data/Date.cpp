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

Date::~Date()
{
}