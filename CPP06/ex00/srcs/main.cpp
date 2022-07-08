#include "Convert.hpp"

int		main(int ac, char **av) {
	if (ac != 2) {
		std::cout << "Usage : ./convert [literal]" << std::endl;
		return (1);
	}
	Convert	c((std::string(av[1])));
	c.print(c.whatType());
	return (0);
}
