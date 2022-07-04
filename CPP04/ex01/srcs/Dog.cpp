#include "Dog.hpp"

Dog::Dog(void) {
	std::cout << "Dog Constructor called" << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
}

Dog::Dog(Dog &d) {
	std::cout << "Dog Copy Constructor called" << std::endl;
	this->_type = d.getType();
	this->_brain = new Brain();
	*this->_brain = *d.getBrain();
}

Dog::~Dog(void) {
	delete this->_brain;
	std::cout << "Dog Destructor called" << std::endl;
}

Dog	&Dog::operator=(Dog &d) {
	this->_type = d.getType();
	delete this->_brain;
	this->_brain = new Brain();
	*this->_brain = *d.getBrain();
	return (*this);
}

void	Dog::makeSound(void) const {
	std::cout << "[Bark]" << std::endl;
}

void	Dog::setBrain(Brain &brain) {
	this->_brain = &brain;
}

Brain	*Dog::getBrain(void) const {
	return(this->_brain);
}