#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class	Fixed {

private :

	int					_raw;
	static const int	_bits = 8;

public :

	Fixed(void);
	Fixed(Fixed &f);
	~Fixed(void);

	Fixed	&operator=(Fixed &f);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);

};


#endif