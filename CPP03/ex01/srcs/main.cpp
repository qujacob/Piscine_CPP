#include "ScavTrap.hpp"

int	main(void) {
	ScavTrap	terry("Terry");

	for (int i = 0; i < 50; i++)
		terry.attack("a bush");
	terry.takeDamage(9);
	terry.beRepaired(123);
	terry.guardGate();
	return (0);
}