#include "FragTrap.hpp"

// CONSTRUCTORS

FragTrap::FragTrap(void) {
	std::cout << "An unnamed fragtrap came to life !" << std::endl;
	this->_name = "Anon";
	this->_hp = 100;
	this->_ep = 100;
	this->_ad = 30;
}

FragTrap::FragTrap(std::string	name) {
	this->_name = name;
	std::cout << this->_name << " (frag) came to life !" << std::endl;
	this->_hp = 100;
	this->_ep = 100;
	this->_ad = 30;
}

FragTrap::FragTrap(FragTrap &st) {
	std::cout << "A clone of " << st.getName() << " (frag) came to life !" << std::endl;
	this->_name = st.getName();
	this->_hp = 100;
	this->_ep = 100;
	this->_ad = 30;
}

// DESTRUCTORS

FragTrap::~FragTrap(void) {
	std::cout << "Farewell, fellow " << this->getName() << " (frag) !" << std::endl;
}

// OPERATORS OVERLOAD

FragTrap	&FragTrap::operator=(FragTrap &st) {
	std::cout << "Implementing " << st.getName() << "'s mind inside " << this->_name << "'s body..." << std::endl;
	std::cout << this->_name.substr(0, 3) << "... " << st.getName() << ": Hi ! I'm " << st.getName() << "!" << std::endl;
	this->_name = st.getName();
	this->_hp = st.getHp();
	this->_ep = st.getEp();
	this->_ad = st.getAd();
	return (*this);
}

// METHODS

void	FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << this->_name << " asked for high fives." << std::endl;
}

void	FragTrap::attack(const std::string &target) {
	if (this->_hp == 0)
		std::cout << "Mr. Stark... I don't feel so good..." << std::endl;
	else if (this->_ep == 0)
		std::cout << "I need battery..." << std::endl;
	else {
		std::cout << "Fragtrap " << this->_name << " attacks " << target << ", causing " << this->_ad << " points of damage !" << std::endl;
		this->_ep--;
	}
}
