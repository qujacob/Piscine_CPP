#include "Animal.hpp"

Animal::Animal(void) {
	this->_type = "Unknown";
}

Animal::Animal(Animal &a) {
	this->_type = a.getType();
}

Animal::~Animal(void) {
}

Animal	&Animal::operator=(Animal &a) {
	this->_type = a.getType();
	return (*this);
}

void		Animal::makeSound(void) const {
	std::cout << "[Inaudible sounds]" << std::endl;
}

std::string	Animal::getType(void) const {
	return (this->_type);
}

void		Animal::setType(std::string type) {
	this->_type = type;
}
