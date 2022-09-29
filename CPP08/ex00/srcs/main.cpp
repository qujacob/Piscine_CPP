#include "easyfind.hpp"

int	main(void) {
	
	std::list<int>	l;
	std::list<int>::iterator it;

	for (int i = 0; i < 5; i++)
		l.push_back(i);

	try {
		it = easyfind(l, 1);
		std::cout << "it: " << *it << std::endl;
		it = easyfind(l, 4);
		std::cout << "it: " << *it << std::endl;
		it = easyfind(l, -3);
		std::cout << "it: " << *it << std::endl;
	}
	catch (NotInConstructorException &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}