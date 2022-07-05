#include "Form.hpp"

Form::Form(void) {
	std::cout << "Creating classic form" << std::endl;
	this->_name = "Paper";
	this->_isSigned = false;
	this->_gradeSign = 140;
	this->_gradeExec = 130;
}

Form::Form(Form &f) {
	std::cout << "Creating a form, copy of form " << f.getName() << std::endl;
	*this = f;
}

Form::Form(std::string name, int sign, int exec) : _name(name) {
	std::cout << "Creating a form " << this->_name << ", gradeSign: " << sign << ", gradeExec: " << exec << std::endl;
	try {
		if (sign > 150)
			throw Form::GradeTooLowException();
		else if (sign < 1)
			throw Form::GradeTooHighException();
		else
			this->_gradeSign = sign;
	}
	catch (Form::GradeTooLowException &e) {
		std::cout << "sign: " << e.what() << std::endl;
		this->_gradeSign = 150;
	}
	catch (Form::GradeTooHighException &e) {
		std::cout << "sign: " << e.what() << std::endl;
		this->_gradeSign = 1;
	}
	try {
		if (exec > this->_gradeSign)
			throw Form::GradeTooLowException();
		else if (exec < 1)
			throw Form::GradeTooHighException();
		else
			this->_gradeExec = exec;
	}
	catch (Form::GradeTooLowException &e) {
		std::cout << "exec: " << e.what() << std::endl;
		this->_gradeExec = this->_gradeSign;
	}
	catch (Form::GradeTooHighException &e) {
		std::cout << "exec: " << e.what() << std::endl;
		this->_gradeExec = 1;
	}
}

Form::~Form(void) {
	std::cout << "Deleting form " << this->_name << std::endl;
}

Form	&Form::operator=(Form &f) {
	this->_name = f.getName();
	this->_isSigned = f.getIsSigned();
	this->_gradeSign = f.getGradeSign();
	this->_gradeExec = f.getGradeExec();
	return (*this);
}

void		Form::beSigned(Bureaucrat &b) {
	if (!this->_isSigned) {
		try {
			if (b.getGrade() > this->_gradeSign)
				throw Form::GradeTooLowException();
			else {
				std::cout << this->_name << " just got signed by " << b.getName() << std::endl;			
				this->_isSigned = true;
			}
		}
		catch (Form::GradeTooLowException &e) {
			std::cout << "beSigned: " << e.what() << std::endl;
		}
	}
	else
		std::cout << "This form has already been signed" << std::endl;
}

std::string	Form::getName(void) const {
	return (this->_name);
}

bool		Form::getIsSigned(void) const {
	return (this->_isSigned);
}

int			Form::getGradeSign(void) const {
	return (this->_gradeSign);
}

int			Form::getGradeExec(void) const {
	return (this->_gradeExec);
}

std::ostream	&operator<<(std::ostream &out, const Form &f) {
	out << "Form " << f.getName() << ": ";
	if (f.getIsSigned())
		out << "is signed, ";
	else
		out << "is not signed, ";
	out << "sign grade: " << f.getGradeSign() << ", exec grade: " << f.getGradeExec();
	return (out);
}