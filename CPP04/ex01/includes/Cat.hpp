#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {

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
