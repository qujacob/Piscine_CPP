#include "Cat.hpp"

Cat::Cat(void) {
	this->_type = "Cat";
}

Cat::Cat(Cat &c) {
	this->_type = c.getType();
}

Cat::~Cat(void) {
}

Cat	&Cat::operator=(Cat &c) {
	this->_type = c.getType();
	return (*this);
}

void	Cat::makeSound(void) const {
	std::cout << "[Meow]" << std::endl;
}
