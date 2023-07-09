#include "RPN.hpp"

int main(int ac, char **av) {

	if (ac == 2) {
		RPN rpn;
		for (int i = 0; av[1][i]; i++) {
			char c = av[1][i];
			if (c >= '0' && c <= '9')
				rpn.push(c - 48);
			else if (c != ' ') {
				if (rpn.size() < 2) {
					std::cerr<< "Error" << std::endl;
					return (1);
				}
				int old = rpn.top();
				rpn.pop();
				switch (c) {
					case '+' :	rpn.top() += old; break;
					case '-' :	rpn.top() -= old; break;
					case '*' :	rpn.top() *= old; break;
					case '/' :	if (old != 0) {rpn.top() /= old; break;} 
								else {std::cerr << "Error" << std::endl; return (1);}
					default :	std::cerr << "Error" << std::endl; return (1);
				}
			}
		}
		if (rpn.size() != 1)
			return (1);
		std::cout << rpn.top() << std::endl;
		return (0);
	}
	std::cerr << "Error : Invalid number of arguments." << std::endl;
	return (1);
}