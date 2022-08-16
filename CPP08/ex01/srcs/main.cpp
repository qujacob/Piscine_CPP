#include "Span.hpp"

int	main() {

	Span	a(10000);

	for (int i = 0; i < 20000; i++) {
		if (i % 2 == 0)
			a.addNumber(i);
	}

	std::cout << a.longestSpan() << std::endl;
	std::cout << a.shortestSpan() << std::endl;
	return (0);
}
