#include "Brain.hpp"

Brain::Brain(void) {
	std::cout << "Creating a Brain..." << std::endl;
	std::string	ideas[100];
	this->_ideas = ideas;
}

Brain::Brain(Brain &b) {
	std::cout << "Creating a Brain (cp)..." << std::endl;
	this->_ideas = b.getIdeas();
}

Brain::~Brain(void) {	
	std::cout << "Deleting a Brain..." << std::endl;
}

Brain	&Brain::operator=(Brain &b) {
	this->_ideas = b.getIdeas();
	return (*this);
}

std::string	*Brain::getIdeas(void) const {
	return (this->_ideas);
}

void		Brain::setIdeas(std::string *ideas) {
	this->_ideas = ideas;
}
