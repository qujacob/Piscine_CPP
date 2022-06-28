#include "ClapTrap.hpp"

int	main(void) {
	ClapTrap	john("John");
	ClapTrap	anon;
	ClapTrap	terry(john);

	john.attack("a bush");
	john.takeDamage(9);
	john.beRepaired(123);
	return (0);
}