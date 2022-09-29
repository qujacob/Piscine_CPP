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
		std::cout << *a << " ";
		a++;
	}
	std::cout << std::endl << "top of stack : " << ms.top() << std::endl;
	ms.pop();
	std::cout << "pop\ntop of stack : " << ms.top() << std::endl << std::endl;
	a = ms.begin();
	b = ms.end();
	while (a != b) {
		std::cout << *a << " ";
		a++;
	}
	std::cout << std::endl;
	return (0);
}