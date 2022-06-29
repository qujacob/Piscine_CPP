#include "Dog.hpp"
#include "Cat.hpp"

#define MAX 2

int main() {
	Animal *tab[MAX];
	for (int i = 0; i < MAX; i++) {
		if (i < MAX / 2)
			tab[i] = new Dog();
		else
			tab[i] = new Cat();
		std::cout << tab[i]->getType() << std::endl;
	}
	std::cout << tab[0]->getBrain()->getIdea(0) << std::endl;
	tab[0]->getBrain()->setIdea("salut mec", 0);
	std::cout << tab[0]->getBrain()->getIdea(0) << std::endl;
	Animal a(*tab[0]);
	std::cout << a.getBrain()->getIdea(0) << std::endl;
	for (int i = 0; i < MAX; i++) {
		tab[i]->makeSound();
		delete tab[i];
	}
	return (0);
}