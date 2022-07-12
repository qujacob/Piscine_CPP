#include "ClapTrap.hpp"

int	main(void) {
	ClapTrap	john("John");
	ClapTrap	anon;
	ClapTrap	john2(john);

	john.attack("a bush");
	john.takeDamage(9);
	john.beRepaired(123);
	for (int i = 0; i < 10; i++)
		john.beRepaired(1);
	return (0);
}