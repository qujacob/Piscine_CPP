#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {

private:

	std::string	_target;

public:

	RobotomyRequestForm(void);
	RobotomyRequestForm(RobotomyRequestForm &rrf);
	RobotomyRequestForm(std::string target);
	~RobotomyRequestForm(void);

	RobotomyRequestForm	&operator=(RobotomyRequestForm &rrf);

	void		execute(const Bureaucrat &executor) const;
	std::string	getTarget(void) const;

};

#endif
