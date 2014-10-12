#ifndef DATE_H
#define DATE_H

class Date
{
public:
	Date(const unsigned int hour, const unsigned int minute, const unsigned int second, const unsigned int year, const unsigned int month, const unsigned int day);
	~Date();

private:
	unsigned int m_hour;
	unsigned int m_minute;
	unsigned int m_second;

	unsigned int m_year;
	unsigned int m_month;
	unsigned int m_day;
};

#endif // DATE_H