#include "Fixed.hpp"

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

Fixed	&Fixed::operator=(const Fixed &f) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_raw = f.getRawBits();
	return (*this);
}

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

std::ostream	&operator<<(std::ostream &out, const Fixed &f) {
	out << f.toFloat();
	return (out);
}