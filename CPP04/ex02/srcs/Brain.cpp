#include "Brain.hpp"

Brain::Brain(void) {
	std::cout << "Brain Constructor called" << std::endl;
	for (int i = 0; i < 100; i++) {
		this->_ideas[i] = "to fill " + std::to_string(i); 
	}
}

Brain::Brain(Brain &b) {
	std::cout << "Brain Copy Constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = b.getIdea(i);
}

Brain::~Brain(void) {
	std::cout << "Brain Destructor called" << std::endl;
}

Brain	&Brain::operator=(Brain &b) {
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = b.getIdea(i);
	return (*this);
}

void		Brain::setIdea(std::string idea, int i) {
	if (i >= 0 && i < 100)
		this->_ideas[i] = idea;
}

std::string	Brain::getIdea(int i) const {
	if (i >= 0 && i < 100)
		return (this->_ideas[i]);
	else
		return ("");
}
