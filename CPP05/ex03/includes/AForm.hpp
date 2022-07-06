#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {

protected:

	std::string	_name;
	bool		_isSigned;
	int			_gradeSign;
	int			_gradeExec;

public:

	AForm(void);
	AForm(AForm &f);
	AForm(std::string name, int sign, int exec);
	virtual ~AForm(void);

	AForm	&operator=(AForm &f);

	void			beSigned(Bureaucrat &b);
	virtual void	execute(const Bureaucrat &executor) const = 0;
	bool			execCheck(const Bureaucrat &executor) const;

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

	class FormNotSignedException : public std::exception {
		public :
			virtual const char *what() const throw() {
				return ("Form is not signed");
			}
	};

};

std::ostream	&operator<<(std::ostream &out, const AForm &f);

#endif
