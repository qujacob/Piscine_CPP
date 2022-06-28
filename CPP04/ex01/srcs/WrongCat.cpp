#include "WrongCat.hpp"

WrongCat::WrongCat(void) {
	this->_type = "WrongCat";
}

WrongCat::WrongCat(WrongCat &c) {
	this->_type = c.getType();
}

WrongCat::~WrongCat(void) {
}

WrongCat	&WrongCat::operator=(WrongCat &c) {
	this->_type = c.getType();
	return (*this);
}

void	WrongCat::makeSound(void) const {
	std::cout << "[Meow]" << std::endl;
}
