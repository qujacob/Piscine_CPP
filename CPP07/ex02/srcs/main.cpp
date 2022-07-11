#include "Array.hpp"

int main(void)
{
	Array<int>		int_nb(12);
	Array<float>	float_nb(12);

	for (int i = 0; i < int_nb.size() + 1; i++) {
		try {
			int_nb[i] = i;
			std::cout << int_nb[i] << " ";
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	for (int i = 0; i < float_nb.size() + 1; i++) {
		try {
			float_nb[i] = i + 0.5;
			std::cout << float_nb[i] << " ";
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	return (0);
}