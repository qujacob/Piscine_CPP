#include "Bureaucrat.hpp"
#include "Form.hpp"

int		main(void) {
	{
		std::cout << "=======================" << std::endl << std::endl;
		Bureaucrat	terry("Terry", 30);
		Form		random("random", 31, 12);
		random.beSigned(terry);
		random.beSigned(terry);
	}
	{
		std::cout << std::endl << "=======================" << std::endl << std::endl;
		Bureaucrat	john("John", 25);
		Form		work("work", 20, 15);
		john.signForm(work);
		for (int i = 0; i < 6; i++) {
			john.upGrade();
			john.signForm(work);
		}
	}
	std::cout << std::endl << "=======================" << std::endl;
	return (0);
}
