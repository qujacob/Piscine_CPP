#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain {

private:

	std::string	*_ideas;

public:

	Brain(void);
	Brain(Brain &b);
	~Brain();

	Brain	&operator=(Brain &b);

	std::string	*getIdeas(void) const;
	void		setIdeas(std::string *ideas);

};

#endif