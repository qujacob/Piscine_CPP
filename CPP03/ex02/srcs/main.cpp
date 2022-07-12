#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void) {
	ScavTrap	terry("Terry");
	FragTrap	john("John");

	john.highFivesGuys();
	terry.attack("a bush");
	terry.takeDamage(9);
	john.attack("Henry");
	terry.guardGate();
	john.highFivesGuys();
	terry.beRepaired(123);
	return (0);
}