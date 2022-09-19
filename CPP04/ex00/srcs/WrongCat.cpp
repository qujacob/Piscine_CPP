#include "WrongCat.hpp"

WrongCat::WrongCat(void) {
	std::cout << "Creating WrongCat" << std::endl;
	this->_type = "WrongCat";
}

WrongCat::WrongCat(WrongCat &c) {
	std::cout << "Creating WrongCat by reference" << std::endl;
	this->_type = c.getType();
}

WrongCat::~WrongCat(void) {
	std::cout << "Destroying WrongCat" << std::endl;
}

WrongCat	&WrongCat::operator=(WrongCat &c) {
	this->_type = c.getType();
	return (*this);
}

void	WrongCat::makeSound(void) const {
	std::cout << "[Meow]" << std::endl;
}
