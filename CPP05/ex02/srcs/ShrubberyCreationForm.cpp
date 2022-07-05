#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) {
	std::cout << "Creating a ShrubberyCreationForm" << std::endl;
	this->_name = "Shrubbery";
	this->_isSigned = false;
	this->_gradeSign = 145;
	this->_gradeExec = 137;
	this->_target = "target";
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &scf) {
	std::cout << "Creating a copy of a ShrubberyCreationForm" << std::endl;
	*this = scf;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : _target(target) {
	std::cout << "Creating a ShrubberyCreationForm that targets " << this->_target << std::endl;
	this->_name = "Shrubbery";
	this->_isSigned = false;
	this->_gradeSign = 145;
	this->_gradeExec = 137;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	std::cout << "Deleting a ShrubberyCreationForm" << std::endl;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm &scf) {
	this->_name = scf.getName();
	this->_isSigned = scf.getIsSigned();
	this->_gradeSign = scf.getGradeSign();
	this->_gradeExec = scf.getGradeExec();
	this->_target = scf.getTarget();
	return (*this);
}

void		ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	if (this->execCheck(executor)) {
		std::cout << this->_target << " Shrubbery" << std::endl;
	}
}

std::string	ShrubberyCreationForm::getTarget(void) const {
	return (this->_target);
}
