#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name) {
	_weapon = NULL;
}

HumanB::~HumanB(void) {
}

void		HumanB::attack(void) {
	if (!this->_weapon)
		std::cout << this->getName() << " doesn't have any weapon" << std::endl;
	else
		std::cout << this->getName() << " attacks with their " << this->getWeapon()->getType() << std::endl;
}

std::string	HumanB::getName(void) const {
	return (this->_name);
}

Weapon		*HumanB::getWeapon(void) const {
	return (this->_weapon);
}

void		HumanB::setWeapon(Weapon &weapon) {
	this->_weapon = &weapon;
}
