#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int		main(void) {
	{
		std::cout << "=======================" << std::endl << std::endl;
		Bureaucrat				terry("Terry", 137);
		ShrubberyCreationForm	scf("scf");

		scf.beSigned(terry);
		terry.signForm(scf);
		terry.executeForm(scf);
		terry.downGrade();
		scf.execute(terry);
	}
	{
		std::cout << std::endl << "=======================" << std::endl << std::endl;
		Bureaucrat			terry("Terry", 45);
		RobotomyRequestForm	rrf("rrf");

		rrf.beSigned(terry);
		terry.signForm(rrf);
		terry.executeForm(rrf);
		terry.downGrade();
		rrf.execute(terry);
	}
	{
		std::cout << std::endl << "=======================" << std::endl << std::endl;
		Bureaucrat				terry("Terry", 5);
		PresidentialPardonForm	ppf("ppf");

		ppf.beSigned(terry);
		terry.signForm(ppf);
		terry.executeForm(ppf);
		terry.downGrade();
		ppf.execute(terry);
	}
	std::cout << std::endl << "=======================" << std::endl;
	return (0);
}
