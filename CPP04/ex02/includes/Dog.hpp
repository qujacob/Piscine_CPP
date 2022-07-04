#ifndef DOG_HPP
# define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {

private :

	Brain	*_brain;

public:
	Dog(void);
	Dog(Dog &d);
	~Dog(void);

	Dog	&operator=(Dog &d);

	virtual void	makeSound(void) const;
	void	setBrain(Brain &brain);
	Brain	*getBrain(void) const;

};

#endif
