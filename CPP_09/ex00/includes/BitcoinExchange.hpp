#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <climits>
#include <list>
#include <iomanip>

class BtcEx {

public:

	BtcEx();
	BtcEx(std::string date, float rate);
	BtcEx(const BtcEx &other);
	~BtcEx();

	BtcEx	&operator=(const BtcEx &other);

	std::string	getDate() const;
	float		getExchangeRate() const;

private:

	std::string	_date;
	float		_exchangeRate;

};

class Date {

public:

	Date();
	Date(std::string date, std::list<BtcEx> &database);
	Date(const Date &other);
	~Date();

	Date	&operator=(const Date &other);

	std::string	previousDate();

	int					getYear() const;
	int					getMonth() const;
	int					getDay() const;
	bool				isValid() const;
	std::list<BtcEx>	*getDatabase() const;

private:

	int					_y;
	int					_m;
	int					_d;
	bool				_isValid;
	std::list<BtcEx>	*_database;

	std::string			_toString();

};

bool	operator==(const Date &left, const Date &right);
bool	operator!=(const Date &left, const Date &right);
bool	operator>(const Date &left, const Date &right);
bool	operator>=(const Date &left, const Date &right);
bool	operator<(const Date &left, const Date &right);
bool	operator<=(const Date &left, const Date &right);