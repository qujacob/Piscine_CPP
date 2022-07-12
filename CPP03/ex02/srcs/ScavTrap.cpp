#include "ScavTrap.hpp"

// CONSTRUCTORS

ScavTrap::ScavTrap(void) {
	std::cout << "An unnamed scavtrap came to life !" << std::endl;
	this->_name = "Anon";
	this->_hp = 100;
	this->_ep = 50;
	this->_ad = 20;
}

ScavTrap::ScavTrap(std::string	name) {
	this->_name = name;
	std::cout << this->_name << " (scav) came to life !" << std::endl;
	this->_hp = 100;
	this->_ep = 50;
	this->_ad = 20;
}

ScavTrap::ScavTrap(ScavTrap &st) {
	std::cout << "A clone of " << st.getName() << " (scav) came to life !" << std::endl;
	this->_name = st.getName();
	this->_hp = 100;
	this->_ep = 50;
	this->_ad = 20;
}

// DESTRUCTORS

ScavTrap::~ScavTrap(void) {
	std::cout << "Farewell, fellow " << this->getName() << " (scav) !" << std::endl;
}

// OPERATORS OVERLOAD

ScavTrap	&ScavTrap::operator=(ScavTrap &st) {
	std::cout << "Implementing " << st.getName() << "'s mind inside " << this->_name << "'s body..." << std::endl;
	std::cout << this->_name.substr(0, 3) << "... " << st.getName() << ": Hi ! I'm " << st.getName() << "!" << std::endl;
	this->_name = st.getName();
	this->_hp = st.getHp();
	this->_ep = st.getEp();
	this->_ad = st.getAd();
	return (*this);
}

// METHODS

void	ScavTrap::guardGate(void) {
	std::cout << "ScavTrap " << this->_name << " entered Gate Keeper mode." << std::endl;
}