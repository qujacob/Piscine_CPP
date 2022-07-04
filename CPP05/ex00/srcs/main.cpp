#include "Bureaucrat.hpp"

int		main(void) {
	{
		std::cout << "=======================" << std::endl << std::endl;
		Bureaucrat	nobody;
		std::cout << nobody << std::endl;
		nobody.downGrade();
		std::cout << nobody << std::endl;
		nobody.upGrade();
		std::cout << nobody << std::endl;
	}
	{
		std::cout << std::endl << "=======================" << std::endl << std::endl;
		Bureaucrat	harold1("Harold", 37);
		std::cout << harold1 << std::endl;
		Bureaucrat	harold2(harold1);
		std::cout << harold2 << std::endl;
	}
	{
		std::cout << std::endl << "=======================" << std::endl << std::endl;
		Bureaucrat	terry("Terry", 1);
		std::cout << terry << std::endl;
		terry.upGrade();
		std::cout << terry << std::endl;
		terry.downGrade();
		std::cout << terry << std::endl;
	}
	{
		std::cout << std::endl << "=======================" << std::endl << std::endl;
		Bureaucrat	john("John", 0);
		std::cout << john << std::endl;
		Bureaucrat	todd("Todd", 151);
		std::cout << todd << std::endl;
	}
	std::cout << std::endl << "=======================" << std::endl;
	return (0);
}
