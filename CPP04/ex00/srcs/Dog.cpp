#include "Dog.hpp"

Dog::Dog(void) {
	this->_type = "Dog";
}

Dog::Dog(Dog &d) {
	this->_type = d.getType();
}

Dog::~Dog(void) {
}

Dog	&Dog::operator=(Dog &d) {
	this->_type = d.getType();
	return (*this);
}

void	Dog::makeSound(void) const {
	std::cout << "[Bark]" << std::endl;
}
