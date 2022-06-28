#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon) {
}

HumanA::~HumanA(void) {
}

void		HumanA::attack(void) {
	std::cout << this->getName() << " attacks with their " << this->getWeapon().getType() << std::endl;
}

std::string	HumanA::getName(void) const {
	return (this->_name);
}

Weapon		HumanA::getWeapon(void) const {
	return (this->_weapon);
}
