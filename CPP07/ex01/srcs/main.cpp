#include "iter.hpp"

template<typename T>
void	setZero(T &elem) {
	elem = 0;
}

template<typename T>
void	increment(T &elem) {
	elem += 48;
}

template<typename T>
void	iter(T *tab, int size, void (*f)(T&)) {
	for (int i = 0; i < size; i++)
		f(tab[i]);
}

int	main( void ) {
	
	int	tab[6] = {0, 1, 2, 3, 4, 5};
	std::string	strs[3] = {"salut", "toi", "mek"};

	iter(tab, 6, &increment);
	std::cout << "[ ";
	for (int i = 0; i < 6; i++)
		std::cout << tab[i] << " ";
	std::cout << "]" << std::endl;

	iter(tab, 6, &setZero);
	std::cout << "[ ";
	for (int i = 0; i < 6; i++)
		std::cout << tab[i] << " ";
	std::cout << "]" << std::endl;

	iter(strs, 3, &increment);
	std::cout << "[ ";
	for (int i = 0; i < 3; i++)
		std::cout << strs[i] << " ";
	std::cout << "]" << std::endl;

	return (0);
}