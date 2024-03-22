#include "Date.h"

Date::Date(int d, int m, int y)
{
    setDate(d, m, y);
}

Date::~Date()
{

}

int Date::getDay() const
{
    return day;
}

int Date::getMonth() const
{
    return month;
}

int Date::getYear() const
{
    return year;
}

void Date::setDay(int day)
{
    this->day = day;
}

void Date::setMonth(int month)
{
    this->month = month;
}

void Date::setYear(int year)
{
    this->year = year;
}

void Date::setDate(int day, int month, int year)
{
    if (isValidDate(day, month, year))
    {
        setDay(day);
        setMonth(month);
        setYear(year);
    }
    else {
        setDay(0);
        setMonth(0);
        setYear(0);
    }
}

void Date::PrintDate() const
{
    std::cout << day << '.' << month << '.' << year;
}

std::string Date::GetFullDate()
{
    return std::to_string(day) + '.' + std::to_string(month) + '.' + std::to_string(year);
}

bool Date::isValidDate(int day, int month, int year)
{
    if ((day < 1 || day>31) || (month < 1 || month>12) || (year < 2020 || year > 2024))
    {
        std::cout << "Not valid date" << std::endl;
        return false;
    }
    return true;
}
