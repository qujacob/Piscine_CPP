#include "Data.hpp"

int	main(void) {
	Data *d1 = new Data();
	uintptr_t ptr = serialize(d1);
	Data *d2 = deserialize(ptr);

	std::cout << "start: " << d1 << std::endl;
	std::cout << "as uintptr_t: " << ptr << std::endl;
	std::cout << "end: " << d2 << std::endl;

	delete d1;
	return (0);
}