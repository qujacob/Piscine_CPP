#include "Intern.hpp"

Intern::Intern(void) {
	std::cout << "Creating an Intern" << std::endl;
}

Intern::Intern(Intern &i) {
	std::cout << "Creating a copy of an Intern" << std::endl;
	*this = i;
}

Intern::~Intern(void) {
	std::cout << "Deleting an Intern" << std::endl;
}

Intern	&Intern::operator=(Intern &i) {
	return (i);
}

AForm	*Intern::makeForm(std::string name, std::string target) const {
	AForm		*ret = NULL;
	std::string	names[3] = {"Shrubbery creation", "Robotomy request", "Presidential pardon"};
	int 		i = -1;

	for (i = 0; i < 3; i++) {
		if (!name.compare(names[i]))
			break ;
	}
	switch (i) {
		case 0 :
			std::cout << "Intern creates " << name << std::endl;
			return ret = new ShrubberyCreationForm(target);
		case 1 :
			std::cout << "Intern creates " << name << std::endl;
			return ret = new RobotomyRequestForm(target);
		case 2 :
			std::cout << "Intern creates " << name << std::endl;
			return ret = new PresidentialPardonForm(target);
		default :
			std::cout << name << " is an unkown form" << std::endl;
	}
	return (ret);
}