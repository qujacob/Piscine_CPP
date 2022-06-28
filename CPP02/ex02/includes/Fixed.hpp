#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class	Fixed {

private :

	int					_raw;
	static const int	_bits = 8;

public :

	Fixed(void);
	Fixed(const int raw);
	Fixed(const float raw);
	Fixed(const Fixed &f);
	~Fixed(void);

	Fixed	&operator=(const Fixed &f);
	Fixed	operator+(const Fixed &f) const;
	Fixed	operator-(const Fixed &f) const;
	Fixed	operator*(const Fixed &f) const;
	Fixed	operator/(const Fixed &f) const;

	bool	operator>(const Fixed &f) const;
	bool	operator<(const Fixed &f) const;
	bool	operator>=(const Fixed &f) const;
	bool	operator<=(const Fixed &f) const;
	bool	operator==(const Fixed &f) const;
	bool	operator!=(const Fixed &f) const;

	Fixed	&operator++(void);
	Fixed	operator++(int);
	Fixed	&operator--(void);
	Fixed	operator--(int);

	int			getRawBits(void) const;
	void		setRawBits(int const raw);
	int			toInt(void) const;
	float		toFloat(void) const;

	static Fixed	&min(Fixed &a, Fixed &b);
	static Fixed	min(const Fixed &a, const Fixed &b);
	static Fixed	&max(Fixed &a, Fixed &b);
	static Fixed	max(const Fixed &a, const Fixed &b);

};

std::ostream	&operator<<(std::ostream &out, const Fixed &f);

#endif