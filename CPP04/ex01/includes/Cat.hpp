#ifndef CAT_H
# define CAT_H

#include "Animal.hpp"

class Cat : public Animal {

public:

	Cat(void);
	Cat(Cat &c);
	virtual ~Cat(void);

	Cat	&operator=(Cat &c);

	virtual void	makeSound(void) const;

};

#endif
