#include "Span.hpp"

int	main() {

	Span	a(12);

	a.addNumbers(13);
	try {
		std::cout << a.longestSpan() << std::endl;
		std::cout << a.shortestSpan() << std::endl;
	}
	catch (Span::SpanSize &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
