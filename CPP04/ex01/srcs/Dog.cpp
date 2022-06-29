#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog(void) {
	std::cout << "Creating a Dog..." << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
}

Dog::Dog(Dog &d) {
	std::cout << "Creating a Dog (cp)..." << std::endl;
	this->_type = d.getType();
	this->_brain = d.getBrain();
}

Dog::~Dog(void) {
	delete this->_brain;
	std::cout << "Deleting a Dog..." << std::endl;
}

Dog	&Dog::operator=(Dog &d) {
	this->_type = d.getType();
	if (this->_brain)
		delete this->_brain;
	this->_brain = new Brain();
	*this->_brain = *d.getBrain();
	return (*this);
}

void	Dog::makeSound(void) const {
	std::cout << "[Bark]" << std::endl;
}
