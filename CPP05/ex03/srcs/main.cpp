#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int		main(void) {
	{
		std::cout << "=======================" << std::endl << std::endl;
		Intern					bob;
		Bureaucrat				terry("Terry", 1);
		AForm	*scf = bob.makeForm("Shrubbery creation", "Bender");

		terry.signForm(*scf);
		terry.executeForm(*scf);
		delete scf;
	}
	{
		std::cout << std::endl << "=======================" << std::endl << std::endl;
		Intern					bob;
		Bureaucrat				terry("Terry", 1);
		AForm	*rrf = bob.makeForm("Robotomy request", "Bender");

		terry.signForm(*rrf);
		terry.executeForm(*rrf);
		delete rrf;
	}
	{
		std::cout << std::endl << "=======================" << std::endl << std::endl;
		Intern					bob;
		Bureaucrat				terry("Terry", 1);
		AForm	*ppf = bob.makeForm("Presidential pardon", "Bender");

		terry.signForm(*ppf);
		terry.executeForm(*ppf);
		delete ppf;
	}
	{
		std::cout << std::endl << "=======================" << std::endl << std::endl;
		Intern					bob;
		Bureaucrat				terry("Terry", 1);
		AForm	*random = bob.makeForm("??????????", "Bender");

		if (random) {
			terry.signForm(*random);
			terry.executeForm(*random);
			delete random;
		}
	}
	std::cout << std::endl << "=======================" << std::endl;
	return (0);
}
