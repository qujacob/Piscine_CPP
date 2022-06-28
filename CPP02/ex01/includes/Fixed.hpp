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

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	int		toInt(void) const;
	float	toFloat(void) const;

};

std::ostream	&operator<<(std::ostream &out, const Fixed &f);

#endif