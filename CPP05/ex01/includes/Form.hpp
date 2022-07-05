#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

private:

	std::string	_name;
	bool		_isSigned;
	int			_gradeSign;
	int			_gradeExec;

public:

	Form(void);
	Form(Form &f);
	Form(std::string name, int sign, int exec);
	~Form(void);

	Form	&operator=(Form &f);

	void		beSigned(Bureaucrat &b);

	std::string	getName(void) const;
	bool		getIsSigned(void) const;
	int			getGradeSign(void) const;
	int			getGradeExec(void) const;

	class GradeTooHighException : public std::exception {
		public :
			virtual const char *what() const throw() {
				return ("Grade value is too high");
			}
	};

	class GradeTooLowException : public std::exception {
		public :
			virtual const char *what() const throw() {
				return ("Grade value is too low");
			}
	};

};

std::ostream	&operator<<(std::ostream &out, const Form &f);

#endif
