#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain {

private:

	std::string	_ideas[100];

public:

	Brain(void);
	Brain(Brain &b);
	~Brain(void);

	Brain	&operator=(Brain &b);

	void		setIdea(std::string idea, int i);
	std::string	getIdea(int i) const;

};


#endif