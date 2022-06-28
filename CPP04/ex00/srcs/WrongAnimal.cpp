#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) {
	this->_type = "Unknown";
}

WrongAnimal::WrongAnimal(WrongAnimal &a) {
	this->_type = a.getType();
}

WrongAnimal::~WrongAnimal(void) {
}

WrongAnimal	&WrongAnimal::operator=(WrongAnimal &a) {
	this->_type = a.getType();
	return (*this);
}

void		WrongAnimal::makeSound(void) const {
	std::cout << "[Inaudible sounds]" << std::endl;
}

std::string	WrongAnimal::getType(void) const {
	return (this->_type);
}

void		WrongAnimal::setType(std::string type) {
	this->_type = type;
}
