#include "ScavTrap.hpp"

int	main(void) {
	ScavTrap	terry("Terry");

	terry.attack("a bush");
	terry.takeDamage(9);
	terry.beRepaired(123);
	return (0);
}