#include "AAnimal.hpp"

AAnimal::AAnimal(void) {
	std::cout << "AAnimal Constructor called" << std::endl;
	this->_type = "Unknown";
}

AAnimal::AAnimal(AAnimal &a) {
	std::cout << "AAnimal Copy Constructor called" << std::endl;
	this->_type = a.getType();
}

AAnimal::~AAnimal(void) {
	std::cout << "AAnimal Destructor called" << std::endl;
}

AAnimal	&AAnimal::operator=(AAnimal &a) {
	this->_type = a.getType();
	return (*this);
}

void		AAnimal::makeSound(void) const {
	std::cout << "[Inaudible sounds]" << std::endl;
}

std::string	AAnimal::getType(void) const {
	return (this->_type);
}

void		AAnimal::setType(std::string type) {
	this->_type = type;
}
