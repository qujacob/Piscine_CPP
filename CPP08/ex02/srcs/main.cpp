#include "MutantStack.hpp"

int	main(void) {
	MutantStack<int>	ms;

	ms.push(3);
	ms.push(1);
	ms.push(2);
	ms.push(4);

	MutantStack<int>::iterator	a = ms.begin();
	MutantStack<int>::iterator	b = ms.end();
	while (a != b) {
		std::cout << *a << std::endl;
		a++;
	}
	std::cout << std::endl << ms.top() << std::endl;
	ms.pop();
	std::cout << ms.top() << std::endl << std::endl;
	a = ms.begin();
	b = ms.end();
	while (a != b) {
		std::cout << *a << std::endl;
		a++;
	}
}