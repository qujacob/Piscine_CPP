#include "Cat.hpp"

Cat::Cat(void) {
	std::cout << "Cat Constructor called" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat(Cat &c) {
	std::cout << "Cat Copy Constructor called" << std::endl;
	this->_type = c.getType();
	this->_brain = new Brain();
	*this->_brain = *c.getBrain();
}

Cat::~Cat(void) {
	delete this->_brain;
	std::cout << "Cat Destructor called" << std::endl;
	
}

Cat	&Cat::operator=(Cat &c) {
	this->_type = c.getType();
	delete this->_brain;
	this->_brain = new Brain();
	*this->_brain = *c.getBrain();
	return (*this);
}

void	Cat::makeSound(void) const {
	std::cout << "[Meow]" << std::endl;
}

void	Cat::setBrain(Brain &brain) {
	this->_brain = &brain;
}

Brain	*Cat::getBrain(void) const {
	return(this->_brain);
}