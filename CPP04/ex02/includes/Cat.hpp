#ifndef CAT_HPP
# define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {

private :

	Brain	*_brain;

public:
	Cat(void);
	Cat(Cat &c);
	~Cat(void);

	Cat	&operator=(Cat &c);

	virtual void	makeSound(void) const;
	void	setBrain(Brain &brain);
	Brain	*getBrain(void) const;

};

#endif
