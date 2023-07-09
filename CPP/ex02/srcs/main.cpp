#include "PmergeMe.hpp"

template <class T>
void	affContainer(T container) {
	for (size_t i = 0; i < container.size(); i++) {
		// if (i == 4 && i < container.size() - 1) {
		// 	std::cout <<  "[...]";
		// 	break;
		// }
		std::cout << container[i] << " ";
	}
	std::cout << std::endl;
}

int	main(int ac, char **av) {
	
	if (ac == 1) {
		std::cerr << "Error : Invalid number of arguments." << std::endl;
		return (1);
	}
	int size = ac - 1;
	int numbers[size];
	for (int i = 1; i < ac; i++) {
		for (int j = 0; av[i][j]; j++)
			if (!std::isdigit(av[i][j])) {
				std::cerr << "Error : Not a positive number." << std::endl;
				return (1);
			}
			else if (std::atol(av[i]) > 2147483647) {
				std::cerr << "Error : Too large number." << std::endl;
				return (1);
			}
		if (!av[i][0]) {
			std::cerr << "Error : Not a positive number." << std::endl;
			return (1);
		}
		numbers[i - 1] = std::atoi(av[i]);
	}

	PmergeMe	pm(numbers, size);
	
	std::cout << "Before (std::vector): ";
	affContainer(pm.getVector());
	pm.vectSort();
	std::cout << "======================================================" << std::endl;
	std::cout << "After (std::vector): ";
	affContainer(pm.getVector());

	std::cout << "Time to process a range of " << pm.getVector().size() << " elements with std::vector : ";
	std::cout << std::fixed << std::setprecision(3) << pm.getVectTime() << " ms" << std::endl;

	std::cout << std::endl;

	std::cout << "Before (std::deque): ";
	affContainer(pm.getDeque());
	pm.dequeSort();
	std::cout << "======================================================" << std::endl;
	std::cout << "After (std::deque): ";
	affContainer(pm.getDeque());

	std::cout << "Time to process a range of " << pm.getDeque().size() << " elements with std::deque : ";
	std::cout << std::fixed << std::setprecision(3) << pm.getVectTime() << " ms" << std::endl;


	return (0);
}
