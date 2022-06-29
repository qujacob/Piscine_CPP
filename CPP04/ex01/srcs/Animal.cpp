#include "Animal.hpp"

Animal::Animal(void) {
	std::cout << "Creating an Animal..." << std::endl;
	this->_type = "Unknown";
	this->_brain = new Brain();
}

Animal::Animal(Animal &a) {
	std::cout << "Creating an Animal (cp)..." << std::endl;
	this->_type = a.getType();
	this->_brain = a.getBrain();
}

Animal::~Animal(void) {
	std::cout << "Deleting an Animal..." << std::endl;
}

Animal	&Animal::operator=(Animal &a) {
	this->_type = a.getType();
	if (this->_brain)
		delete this->_brain;
	this->_brain = new Brain();
	*this->_brain = *a.getBrain();
	return (*this);
}

void		Animal::makeSound(void) const {
	std::cout << "[Inaudible sounds]" << std::endl;
}

std::string	Animal::getType(void) const {
	return (this->_type);
}

Brain		*Animal::getBrain(void) const {
	return (this->_brain);
}

void		Animal::setType(std::string type) {
	this->_type = type;
}

void		Animal::setBrain(Brain *brain) {
	this->_brain = brain;
}
