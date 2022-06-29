#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain {

private:

	std::string	_ideas[100];

public:

	Brain(void);
	Brain(Brain &b);
	~Brain();

	Brain	&operator=(Brain &b);

	std::string	getIdea(int i) const;
	void		setIdea(std::string idea, int i);

};

#endif