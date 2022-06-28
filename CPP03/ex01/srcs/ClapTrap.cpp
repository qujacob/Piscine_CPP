#include "ClapTrap.hpp"

// CONSTRUCTORS

ClapTrap::ClapTrap(void) {
	std::cout << "An unnamed robot came to life !" << std::endl;
	this->_name = "Anon";
	this->_hp = 10;
	this->_ep = 10;
	this->_ad = 0;
}

ClapTrap::ClapTrap(std::string	name) : _name(name) {
	std::cout << this->_name << " came to life !" << std::endl;
	this->_hp = 10;
	this->_ep = 10;
	this->_ad = 0;
}

ClapTrap::ClapTrap(ClapTrap &ct) {
	std::cout << "A clone of " << ct.getName() << " came to life !" << std::endl;
	this->_name = ct.getName();
	this->_hp = 10;
	this->_ep = 10;
	this->_ad = 0;
}

// DESTRUCTORS

ClapTrap::~ClapTrap(void) {
	std::cout << "Farewell, fellow " << this->getName() << "!" << std::endl;
}

// OPERATORS OVERLOAD

ClapTrap	&ClapTrap::operator=(ClapTrap &ct) {
	std::cout << "Implementing " << ct.getName() << "'s mind inside " << this->_name << "'s body..." << std::endl;
	std::cout << this->_name.substr(0, 3) << "... " << ct.getName() << ": Hi ! I'm " << ct.getName() << "!" << std::endl;
	this->_name = ct.getName();
	this->_hp = ct.getHp();
	this->_ep = ct.getEp();
	this->_ad = ct.getAd();
	return (*this);
}

// METHODS

void		ClapTrap::attack(const std::string &target) {
	if (this->_hp == 0)
		std::cout << "Mr. Stark... I don't feel so good..." << std::endl;
	else if (this->_ep == 0)
		std::cout << "I need battery..." << std::endl;
	else {
		std::cout << "Claptrap " << this->_name << " attacks " << target << ", causing " << this->_ad << " points of damage !" << std::endl;
		this->_ep--;
	}
}

void		ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "Outch ! " << this->_name << " just lost " << amount << " HP !" << std::endl;
	this->_hp -= amount;
	if (this->_hp < 0)
		this->_hp = 0;
}

void		ClapTrap::beRepaired(unsigned int amount) {
	if (this->_hp == 0)
		std::cout << "Mr. Stark... I don't feel so good..." << std::endl;
	else if (this->_ep == 0)
		std::cout << "I need battery..." << std::endl;
	else {
		std::cout << "Time to rest, thanks mech ! I just restored " << amount << " HP !" << std::endl;
		this->_hp += amount;
		this->_ep--;
	}
}

// SETTERS

void		ClapTrap::setName(std::string name) {
	this->_name = name;
}

void		ClapTrap::setHp(int hp) {
	this->_hp = hp;
}

void		ClapTrap::setEp(int ep) {
	this->_ep = ep;
}

void		ClapTrap::setAd(int ad) {
	this->_ad = ad;
}

// GETTERS

std::string	ClapTrap::getName(void) const {
	return (this->_name);
}

int			ClapTrap::getHp(void) const {
	return (this->_hp);
}

int			ClapTrap::getEp(void) const {
	return (this->_ep);
}

int			ClapTrap::getAd(void) const {
	return (this->_ad);
}
