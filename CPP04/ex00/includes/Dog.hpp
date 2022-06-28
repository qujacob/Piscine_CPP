#ifndef DOG_H
# define DOG_H

#include "Animal.hpp"

class Dog : public Animal {

public:
	Dog(void);
	Dog(Dog &d);
	~Dog(void);

	Dog	&operator=(Dog &d);

	virtual void	makeSound(void) const;

};

#endif
