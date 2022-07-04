#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>

class AAnimal {

protected :

	std::string	_type;

public :

	AAnimal(void);
	AAnimal(AAnimal &a);
	virtual ~AAnimal(void);

	AAnimal	&operator=(AAnimal &a);

	virtual void	makeSound(void) const = 0;
	void			setType(std::string type);
	std::string		getType(void) const;

};

#endif