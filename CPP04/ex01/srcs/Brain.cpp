#include "Brain.hpp"

Brain::Brain(void) {
	std::cout << "Creating a Brain..." << std::endl;
}

Brain::Brain(Brain &b) {
	std::cout << "Creating a Brain (cp)..." << std::endl;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = b.getIdea(i);
}

Brain::~Brain(void) {	
	std::cout << "Deleting a Brain..." << std::endl;
}

Brain	&Brain::operator=(Brain &b) {
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = b.getIdea(i);
	return (*this);
}

std::string	Brain::getIdea(int i) const {
	if (i < 0 || i >= 100) {
		std::cout << "Invalid index (0 - 99)" << std::endl;
		return (NULL);
	}
	return (this->_ideas[i]);
}

void		Brain::setIdea(std::string idea, int i) {
	if (i < 0 || i >= 100)
		std::cout << "Invalid index (0 - 99)" << std::endl;
	this->_ideas[i] = idea;
}
