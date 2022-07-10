#include "Base.hpp"

int	main(void) {
	Base	*b = generate();
	identify(b);
	std::cout << "===============" << std::endl;
	identify(*b);
	delete b;
	return (0);
}