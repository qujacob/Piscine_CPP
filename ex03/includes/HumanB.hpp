#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class	HumanB {

public :

	HumanB(std::string name);
	~HumanB(void);

	void		attack(void);
	std::string	getName(void) const;
	Weapon		*getWeapon(void) const;
	void		setWeapon(Weapon &weapon);

private :

	std::string	_name;
	Weapon		*_weapon;

};

#endif