#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {

private:

	std::string	_target;

public:

	ShrubberyCreationForm(void);
	ShrubberyCreationForm(ShrubberyCreationForm &scf);
	ShrubberyCreationForm(std::string target);
	~ShrubberyCreationForm(void);

	ShrubberyCreationForm	&operator=(ShrubberyCreationForm &scf);

	void		execute(const Bureaucrat &executor) const;
	std::string	getTarget(void) const;

};

#endif
