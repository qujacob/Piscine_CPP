#include <iostream>

int	main(void) {
	std::string	str = "HI THIS IS BRAIN";
	std::string	*strPTR = &str;
	std::string	&strREF = str;

	std::cout << "str : " << &str << "; strPR : " << strPTR << "; strREF : " << &strREF << std::endl;
	std::cout << "str : " << str << "; strPR : " << *strPTR << "; strREF : " << strREF << std::endl;

	return (0);
}