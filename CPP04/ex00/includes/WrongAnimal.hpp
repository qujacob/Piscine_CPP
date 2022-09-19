#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {

protected :

	std::string	_type;

public :

	WrongAnimal(void);
	WrongAnimal(WrongAnimal &a);
	virtual ~WrongAnimal(void);

	WrongAnimal	&operator=(WrongAnimal &a);

	void	makeSound(void) const;
	void			setType(std::string type);
	std::string		getType(void) const;

};

#endif