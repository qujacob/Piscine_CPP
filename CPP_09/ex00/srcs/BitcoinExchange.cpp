#include "BitcoinExchange.hpp"

// 	BTC CLASS //

BtcEx::BtcEx() : _date(""), _exchangeRate(0) {}

BtcEx::BtcEx(std::string date, float rate) : _date(date), _exchangeRate(rate) {}

BtcEx::BtcEx(const BtcEx &other) { *this = other; }

BtcEx::~BtcEx() {}

BtcEx	&BtcEx::operator=(const BtcEx &other) {
	_date = other.getDate();
	_exchangeRate = other.getExchangeRate();
	return (*this);
}

std::string	BtcEx::getDate() const { return (_date); }

float		BtcEx::getExchangeRate() const { return (_exchangeRate); }

// DATE CLASS //

Date::Date() : _y(0), _m(0), _d(0), _isValid(0) {}

Date::Date(std::string date, std::list<BtcEx> &database) {
	_database = &database;
	_y = atof(date.substr(0, date.find('-')).c_str());
	date.erase(0, date.find('-') + 1);
	_m = atof(date.substr(0, date.find('-')).c_str());
	date.erase(0, date.find('-') + 1);
	_d = atof(date.substr(0, date.find('-')).c_str());
	if (_y > 2023 || _m > 12 || _d > 31 || _y < 2009 || _m == 0 || _d == 0 || (_y == 2009 && _m == 1 && _d == 1)) {
		_isValid = 0;
	}
	else if (_d > 30 && (_m == 4 || _m == 6 || _m == 9 || _m == 11))
		_isValid = 0;
	else if (_m == 2 && ((_y % 4 == 0 && _d > 29) || (_y % 4 != 0 && _d > 28)))
		_isValid = 0;
	else
		_isValid = 1;
}

Date::Date(const Date &other) { *this = other; }

Date::~Date() {}

Date				&Date::operator=(const Date &other) {
	_y = other.getYear();
	_m = other.getMonth();
	_d = other.getDay();
	_isValid = other.isValid();
	_database = other.getDatabase();
	return (*this);
}

std::string			Date::_toString() {
	std::string date = static_cast<std::ostringstream*>( &(std::ostringstream() << _y))->str();
	date += "-";
	std::string month = static_cast<std::ostringstream*>( &(std::ostringstream() << _m))->str();
	if (month.length() == 1)
		date += "0";
	date += month;
	date += "-";
	std::string day = static_cast<std::ostringstream*>( &(std::ostringstream() << _d))->str();
	if (day.length() == 1)
		date += "0";
	date += day;

	return date;
}

std::string			Date::previousDate() {
	std::list<BtcEx>::iterator	it = _database->begin();
	while (it != _database->end()) {
		Date date(it->getDate(), *_database);
		if (date < *this) {
			it++;
		}
		else {
			if (date != *this)
				it--;
			Date prev(it->getDate(), *_database);
			while (prev < *this) {
				_d--;
				if (_d == 0) {
					_m--;
					if (_m == 0) {
						_y--;
						_m = 12;
					}
					if (_m == 4 || _m == 6 || _m == 9 || _m == 11)
						_d = 30;
					else if (_m == 2)
						_y % 4 == 0 ? _d = 29 : _d = 28;
					else
						_d = 31;
				}
			}
			break ;
		}
	}
	return _toString();
}

int					Date::getYear() const { return (_y); }

int					Date::getMonth() const { return (_m); }

int					Date::getDay() const { return (_d); }

bool				Date::isValid() const { return (_isValid); }

std::list<BtcEx>	*Date::getDatabase() const { return (_database); }


bool	operator==(const Date &left, const Date &right) {
	if (left.getYear() == right.getYear() && left.getMonth() == right.getMonth() && left.getDay() == right.getDay())
		return (true);
	return (false);
}

bool	operator!=(const Date &left, const Date &right) {
	return !(left == right);
}

bool	operator>(const Date &left, const Date &right) {
	if (left.getYear() > right.getYear() ||
		(left.getYear() == right.getYear() && left.getMonth() > right.getMonth()) ||
		(left.getYear() == right.getYear() && left.getMonth() == right.getMonth() && left.getDay() > right.getDay()))
		return (true);
	return (false);
}

bool	operator>=(const Date &left, const Date &right) {
	if (left.getYear() >= right.getYear() ||
		(left.getYear() == right.getYear() && left.getMonth() >= right.getMonth()) ||
		(left.getYear() == right.getYear() && left.getMonth() == right.getMonth() && left.getDay() >= right.getDay()))
		return (true);
	return (false);
}

bool	operator<(const Date &left, const Date &right) {
	if (left.getYear() < right.getYear() ||
		(left.getYear() == right.getYear() && left.getMonth() < right.getMonth()) ||
		(left.getYear() == right.getYear() && left.getMonth() == right.getMonth() && left.getDay() < right.getDay()))
		return (true);
	return (false);
}

bool	operator<=(const Date &left, const Date &right) {
	if (left.getYear() <= right.getYear() ||
		(left.getYear() == right.getYear() && left.getMonth() <= right.getMonth()) ||
		(left.getYear() == right.getYear() && left.getMonth() == right.getMonth() && left.getDay() <= right.getDay()))
		return (true);
	return (false);
}