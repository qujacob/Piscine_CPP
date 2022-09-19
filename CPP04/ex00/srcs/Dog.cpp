#include "Dog.hpp"

Dog::Dog(void) {
	std::cout << "Creating Dog" << std::endl;
	this->_type = "Dog";
}

Dog::Dog(Dog &d) {
	std::cout << "Creating Dog by reference" << std::endl;
	this->_type = d.getType();
}

Dog::~Dog(void) {
	std::cout << "Destroying Dog" << std::endl;
}

Dog	&Dog::operator=(Dog &d) {
	this->_type = d.getType();
	return (*this);
}

void	Dog::makeSound(void) const {
	std::cout << "[Bark]" << std::endl;
}
