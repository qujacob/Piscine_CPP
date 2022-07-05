#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) {
	std::cout << "Creating a PresidentialPardonForm" << std::endl;
	this->_name = "Presidential";
	this->_isSigned = false;
	this->_gradeSign = 25;
	this->_gradeExec = 5;
	this->_target = "target";
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &ppf) {
	std::cout << "Creating a copy of a PresidentialPardonForm" << std::endl;
	*this = ppf;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : _target(target) {
	std::cout << "Creating a PresidentialPardonForm that targets " << this->_target << std::endl;
	this->_name = "Presidential";
	this->_isSigned = false;
	this->_gradeSign = 25;
	this->_gradeExec = 5;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
	std::cout << "Deleting a PresidentialPardonForm" << std::endl;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm &ppf) {
	this->_name = ppf.getName();
	this->_isSigned = ppf.getIsSigned();
	this->_gradeSign = ppf.getGradeSign();
	this->_gradeExec = ppf.getGradeExec();
	this->_target = ppf.getTarget();
	return (*this);
}

void		PresidentialPardonForm::execute(const Bureaucrat &executor) const {
	if (this->execCheck(executor)) {
		std::cout << this->_target << " Presidential" << std::endl;
	}
}

std::string	PresidentialPardonForm::getTarget(void) const {
	return (this->_target);
}
