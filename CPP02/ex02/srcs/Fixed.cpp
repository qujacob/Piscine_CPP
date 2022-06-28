#include "Fixed.hpp"

// [CONSTRUCTORS & DESTRUCTORS]

Fixed::Fixed(void) {
	std::cout << "Default constructor called" << std::endl;
	this->_raw = 0;
}

Fixed::Fixed(const Fixed &f) {
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Fixed::Fixed(const int raw) {
	this->_raw = raw << this->_bits;
}

Fixed::Fixed(const float raw) {
	this->_raw = roundf(raw * (1 << this->_bits));
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

// [OPERATORS OVERLOAD]

Fixed	&Fixed::operator=(const Fixed &f) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_raw = f.getRawBits();
	return (*this);
}

Fixed	Fixed::operator+(const Fixed &f) const {
	return (Fixed(this->toFloat() + f.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &f) const {
	return (Fixed(this->toFloat() - f.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &f) const {
	return (Fixed(this->toFloat() * f.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &f) const{
	return (Fixed(this->toFloat() / f.toFloat()));
}

bool	Fixed::operator>(const Fixed &f) const {
	return (this->_raw > f.getRawBits());
}

bool	Fixed::operator<(const Fixed &f) const {
	return (this->_raw < f.getRawBits());
}

bool	Fixed::operator>=(const Fixed &f) const {
	return (this->_raw >= f.getRawBits());
}

bool	Fixed::operator<=(const Fixed &f) const {
	return (this->_raw <= f.getRawBits());
}

bool	Fixed::operator==(const Fixed &f) const {
	return (this->_raw == f.getRawBits());
}

bool	Fixed::operator!=(const Fixed &f) const {
	return (this->_raw != f.getRawBits());
}

Fixed	&Fixed::operator++(void) {
	this->_raw++;
	return (*this);
}

Fixed	Fixed::operator++(int) {
	Fixed tmp = *this;
	++*this;
	return (tmp);
}

Fixed	&Fixed::operator--(void) {
	this->_raw--;
	return (*this);
}

Fixed	Fixed::operator--(int) {
	Fixed tmp = *this;
	--*this;
	return (tmp);
}

// [MEMBER METHODS]

int		Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_raw);
}

void	Fixed::setRawBits(int const raw) {
	this->_raw = raw;
}

int		Fixed::toInt(void) const {
	return (this->_raw >> this->_bits);
}

float	Fixed::toFloat(void) const {
	return ((float)this->_raw / (float)(1 << this->_bits));
}

Fixed	&Fixed::min(Fixed &a, Fixed &b) {
	if (a <= b)
		return (a);
	return (b);
}

Fixed	Fixed::min(const Fixed &a, const Fixed &b) {
	if (a <= b)
		return (a);
	return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b) {
	if (a >= b)
		return (a);
	return (b);
}

Fixed	Fixed::max(const Fixed &a, const Fixed &b) {
	if (a >= b)
		return (Fixed(a));
	return (Fixed(b));
}

// [OUTSIDERS]

std::ostream	&operator<<(std::ostream &out, const Fixed &f) {
	out << f.toFloat();
	return (out);
}