#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal {

protected :

	std::string	_type;

public :

	Animal(void);
	Animal(Animal &a);
	virtual ~Animal(void);

	Animal	&operator=(Animal &a);

	virtual void	makeSound(void) const;
	void			setType(std::string type);
	std::string		getType(void) const;

};

#endif