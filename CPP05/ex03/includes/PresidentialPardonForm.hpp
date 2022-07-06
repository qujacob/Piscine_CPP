#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {

private:

	std::string	_target;

public:

	PresidentialPardonForm(void);
	PresidentialPardonForm(PresidentialPardonForm &ppf);
	PresidentialPardonForm(std::string target);
	~PresidentialPardonForm(void);

	PresidentialPardonForm	&operator=(PresidentialPardonForm &ppf);

	void		execute(const Bureaucrat &executor) const;
	std::string	getTarget(void) const;

};

#endif
