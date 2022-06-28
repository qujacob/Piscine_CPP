#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat(void) {
	std::cout << "Creating a Cat..." << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat(Cat &c) {
	std::cout << "Creating a Cat (cp)..." << std::endl;
	this->_type = c.getType();
	this->_brain = c.getBrain();
}

Cat::~Cat(void) {
	delete this->_brain;
	std::cout << "Deleting a Cat..." << std::endl;
}

Cat	&Cat::operator=(Cat &c) {
	this->_type = c.getType();
	return (*this);
}

void	Cat::makeSound(void) const {
	std::cout << "[Meow]" << std::endl;
}
