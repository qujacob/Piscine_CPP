#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class Animal {

protected :

	std::string	_type;
	Brain	*_brain;

public :

	Animal(void);
	Animal(Animal &a);
	virtual ~Animal(void);

	Animal	&operator=(Animal &a);

	virtual void	makeSound(void) const;
	void			setType(std::string type);
	void			setBrain(Brain *brain);
	std::string		getType(void) const;
	Brain			*getBrain(void) const;

};

#endif