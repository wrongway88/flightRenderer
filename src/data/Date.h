#ifndef DATE_H
#define DATE_H

#include <string>
#include <tuple>

class Date
{
public:
	Date(const unsigned int hour, const unsigned int minute, const unsigned int second, const unsigned int year, const unsigned int month, const unsigned int day);
	Date(const std::string& dateString);
	~Date();

private:
	std::tuple<std::tuple<unsigned int, unsigned int, unsigned int>, std::tuple<unsigned int, unsigned int, unsigned int>> parseDateString(const std::string& dateString);
	std::tuple<unsigned int, unsigned int, unsigned int> parseDate(const std::string& date);
	std::tuple<unsigned int, unsigned int, unsigned int> parseTime(const std::string& time);

	unsigned int m_hour;
	unsigned int m_minute;
	unsigned int m_second;

	unsigned int m_year;
	unsigned int m_month;
	unsigned int m_day;
};

#endif // DATE_H