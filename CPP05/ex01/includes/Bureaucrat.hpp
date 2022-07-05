#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat {

private :

	std::string	_name;
	int			_grade;

public :

	Bureaucrat(void);
	Bureaucrat(Bureaucrat &b);
	Bureaucrat(std::string name, int grade);
	~Bureaucrat(void);

	Bureaucrat	&operator=(Bureaucrat &b);

	void		upGrade(void);
	void		downGrade(void);
	void		signForm(Form &f);

	std::string	getName(void) const;
	int			getGrade(void) const;

	class GradeTooHighException : public std::exception {
		public :
			virtual const char *what() const throw() {
				return ("Grade value would be too high...");
			}
	};

	class GradeTooLowException : public std::exception {
		public :
			virtual const char *what() const throw() {
				return ("Grade value would be too low...");
			}
	};

};

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &b);

#endif
