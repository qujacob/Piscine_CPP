#ifndef SCAVTRAP_H
# define SCAVTRAP_H

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

public:

	ScavTrap(void);
	ScavTrap(std::string name);
	ScavTrap(ScavTrap &st);
	virtual ~ScavTrap(void);

	ScavTrap	&operator=(ScavTrap &st);

	void		guardGate(void);
	void		attack(const std::string &target);
	
};

#endif