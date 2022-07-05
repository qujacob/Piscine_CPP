#include "AForm.hpp"

AForm::AForm(void) {
	std::cout << "Creating classic form" << std::endl;
	this->_name = "Paper";
	this->_isSigned = false;
	this->_gradeSign = 140;
	this->_gradeExec = 130;
}

AForm::AForm(AForm &f) {
	std::cout << "Creating a form, copy of form " << f.getName() << std::endl;
	*this = f;
}

AForm::AForm(std::string name, int sign, int exec) : _name(name) {
	std::cout << "Creating a form " << this->_name << ", gradeSign: " << sign << ", gradeExec: " << exec << std::endl;
	try {
		if (sign > 150)
			throw AForm::GradeTooLowException();
		else if (sign < 1)
			throw AForm::GradeTooHighException();
		else
			this->_gradeSign = sign;
	}
	catch (AForm::GradeTooLowException &e) {
		std::cout << "sign: " << e.what() << std::endl;
		this->_gradeSign = 150;
	}
	catch (AForm::GradeTooHighException &e) {
		std::cout << "sign: " << e.what() << std::endl;
		this->_gradeSign = 1;
	}
	try {
		if (exec > this->_gradeSign)
			throw AForm::GradeTooLowException();
		else if (exec < 1)
			throw AForm::GradeTooHighException();
		else
			this->_gradeExec = exec;
	}
	catch (AForm::GradeTooLowException &e) {
		std::cout << "exec: " << e.what() << std::endl;
		this->_gradeExec = this->_gradeSign;
	}
	catch (AForm::GradeTooHighException &e) {
		std::cout << "exec: " << e.what() << std::endl;
		this->_gradeExec = 1;
	}
}

AForm::~AForm(void) {
	std::cout << "Deleting form " << this->_name << std::endl;
}

AForm	&AForm::operator=(AForm &f) {
	this->_name = f.getName();
	this->_isSigned = f.getIsSigned();
	this->_gradeSign = f.getGradeSign();
	this->_gradeExec = f.getGradeExec();
	return (*this);
}

void		AForm::beSigned(Bureaucrat &b) {
	if (!this->_isSigned) {
		try {
			if (b.getGrade() > this->_gradeSign)
				throw AForm::GradeTooLowException();
			else {
				std::cout << this->_name << " just got signed by " << b.getName() << std::endl;			
				this->_isSigned = true;
			}
		}
		catch (AForm::GradeTooLowException &e) {
			std::cout << "beSigned: " << e.what() << std::endl;
		}
	}
	else
		std::cout << "This form has already been signed" << std::endl;
}

bool		AForm::execCheck(const Bureaucrat &executor) const{
	try {
		if (!this->_isSigned)
			throw AForm::FormNotSignedException();
		else if (this->_gradeExec < executor.getGrade())
			throw AForm::GradeTooLowException();
	}
	catch (AForm::FormNotSignedException &e) {
		std::cout << "execCheck: " << e.what() << std::endl;
		return (false);
	}
	catch (AForm::GradeTooLowException &e) {
		std::cout << "execCheck: " << e.what() << std::endl;
		return (false);
	}
	return (true);
}

std::string	AForm::getName(void) const {
	return (this->_name);
}

bool		AForm::getIsSigned(void) const {
	return (this->_isSigned);
}

int			AForm::getGradeSign(void) const {
	return (this->_gradeSign);
}

int			AForm::getGradeExec(void) const {
	return (this->_gradeExec);
}

std::ostream	&operator<<(std::ostream &out, const AForm &f) {
	out << "Form " << f.getName() << ": ";
	if (f.getIsSigned())
		out << "is signed, ";
	else
		out << "is not signed, ";
	out << "sign grade: " << f.getGradeSign() << ", exec grade: " << f.getGradeExec();
	return (out);
}