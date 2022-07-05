#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) {
	std::cout << "Creating a new bureaucrat" << std::endl;
	this->_name = "Unknown";
	this->_grade = 150;
}

Bureaucrat::Bureaucrat(Bureaucrat &b) {
	std::cout << "Creating a new bureaucrat similar to " << b.getName() << std::endl;
	*this = b;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
	std::cout << "Creating a new bureaucrat named " << name << ", grade "<< grade << std::endl;
	try {
		if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
		else if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		else
			this->_grade = grade;
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << "grade: " << e.what() << std::endl;
		this->_grade = 150;
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << "grade: " << e.what() << std::endl;
		this->_grade = 1;
	}
}

Bureaucrat::~Bureaucrat(void) {
	std::cout << "Deleting bureaucrat " << this->_name << ", grade " << this->_grade << std::endl;
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat &b) {
	this->_name = b.getName();
	this->_grade = b.getGrade();
	return (*this);
}

void		Bureaucrat::upGrade(void) {
	try {
		if (this->_grade - 1 < 1)
			throw Bureaucrat::GradeTooHighException();
		else
			this->_grade--;
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << "upGrade: " << e.what() << std::endl;
	}
}

void		Bureaucrat::downGrade(void) {
	try {
		if (this->_grade + 1 > 150)
			throw Bureaucrat::GradeTooLowException();
		else
			this->_grade++;
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << "downGrade: " << e.what() << std::endl;
	}
}

void		Bureaucrat::signForm(Form &f) {
	if (!f.getIsSigned()) {
		if (this->_grade <= f.getGradeSign()) {
			std::cout << this->_name << " signed " << f.getName() << std::endl;
			f.beSigned(*this);
		}
		else 
			std::cout << this->_name << " couldn't sign " << f.getName() << " because of their low grade." << std::endl; 
	}
	else
		std::cout << this->_name << " couldn't sign " << f.getName() << " because it already has been" << std::endl;
}

std::string	Bureaucrat::getName(void) const {
	return (this->_name);
}

int			Bureaucrat::getGrade(void) const {
	return (this->_grade);
}

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &b) {
	out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return (out);
}