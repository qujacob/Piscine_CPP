#include "Cat.hpp"

Cat::Cat(void) {
	std::cout << "Creating Cat" << std::endl;
	this->_type = "Cat";
}

Cat::Cat(Cat &c) {
	std::cout << "Creating Cat by reference" << std::endl;
	this->_type = c.getType();
}

Cat::~Cat(void) {
	std::cout << "Destroying Cat" << std::endl;
}

Cat	&Cat::operator=(Cat &c) {
	this->_type = c.getType();
	return (*this);
}

void	Cat::makeSound(void) const {
	std::cout << "[Meow]" << std::endl;
}
