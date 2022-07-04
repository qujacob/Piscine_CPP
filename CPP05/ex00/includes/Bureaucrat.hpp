#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {

private :

	std::string	_name;
	int			_grade;

public :

	class GradeTooHighException {
		public :
			virtual const char *what() const throw() {
				return ("Grade value would be too high...");
			}
	};

	class GradeTooLowException {
		public :
			virtual const char *what() const throw() {
				return ("Grade value would be too low...");
			}
	};

	Bureaucrat(void);
	Bureaucrat(Bureaucrat &b);
	Bureaucrat(std::string name, int grade);
	~Bureaucrat(void);

	Bureaucrat	&operator=(Bureaucrat &b);

	void		upGrade(void);
	void		downGrade(void);

	std::string	getName(void) const;
	int			getGrade(void) const;


};

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &b);

#endif
