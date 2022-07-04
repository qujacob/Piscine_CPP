#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	{
		std::cout << std::endl;
		std::cout << "==============================================" << std::endl;
		std::cout << std::endl;

		Cat cat;
		std::cout << std::endl;
		Cat cat2;
		std::cout << std::endl;
		cat2 = cat;
		std::cout << std::endl;
		cat2.getBrain()->setIdea("J'aime le pâté", 50);
		std::cout << "cat.getIdea(50) = " << cat.getBrain()->getIdea(50) << std::endl;
		std::cout << "cat2.getType() = " << cat2.getType() << std::endl;
		std::cout << "cat2.makeSound() = "; cat2.makeSound();
		std::cout << std::endl;
		std::cout << "cat2.getIdea(50) = " << cat2.getBrain()->getIdea(50) << std::endl;
		std::cout << "cat2.getType() = " << cat2.getType() << std::endl;
		std::cout << "cat2.makeSound() = "; cat2.makeSound();
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << "==============================================" << std::endl;
	std::cout << std::endl;
}