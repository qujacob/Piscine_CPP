#include "Base.hpp"

Base::~Base(void) {}

A::A() {}

A::~A() {}

B::B() {}

B::~B() {}

C::C() {}

C::~C() {}

Base	*generate(void) {
	srand((unsigned int) time(NULL));
	int random = rand() % 3;

	if (random == 0)
		return (new A());
	else if (random == 1)
		return (new B());
	return (new C());
}

void	identify(Base *p) {
	if (A *a = dynamic_cast<A*>(p))
		std::cout << "Type: A" << std::endl;
	else if (B *b = dynamic_cast<B*>(p))
		std::cout << "Type: B" << std::endl;
	else if (C *c = dynamic_cast<C*>(p))
		std::cout << "Type: C" << std::endl;
}

void	identify(Base &p) {
	try {
		A a = dynamic_cast<A&>(p);
		std::cout << "Type: A" << std::endl;
	}
	catch(const std::exception& e) {}
	try {
		B b = dynamic_cast<B&>(p);
		std::cout << "Type: B" << std::endl;
	}
	catch(const std::exception& e) {}
	try {
		C c = dynamic_cast<C&>(p);
		std::cout << "Type: C" << std::endl;
	}
	catch(const std::exception& e) {}
}