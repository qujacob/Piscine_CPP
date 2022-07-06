#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) {
	std::cout << "Creating a RobotomyRequestForm" << std::endl;
	this->_name = "Robotomy request";
	this->_isSigned = false;
	this->_gradeSign = 72;
	this->_gradeExec = 45;
	this->_target = "target";
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &rrf) {
	std::cout << "Creating a copy of a RobotomyRequestForm" << std::endl;
	*this = rrf;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : _target(target) {
	std::cout << "Creating a RobotomyRequestForm that targets " << this->_target << std::endl;
	this->_name = "Robotomy request";
	this->_isSigned = false;
	this->_gradeSign = 72;
	this->_gradeExec = 45;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
	std::cout << "Deleting a RobotomyRequestForm" << std::endl;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm &rrf) {
	this->_name = rrf.getName();
	this->_isSigned = rrf.getIsSigned();
	this->_gradeSign = rrf.getGradeSign();
	this->_gradeExec = rrf.getGradeExec();
	this->_target = rrf.getTarget();
	return (*this);
}

void		RobotomyRequestForm::execute(const Bureaucrat &executor) const {
	if (this->execCheck(executor)) {
		std::cout << "Wuuuuuuw wuw wuuuuuuuuuu..." << std::endl;
		srand((unsigned int) time(NULL));
		int random = rand() % 2;
		if (random)
			std::cout << this->_target << " has been robotomized" << std::endl;
		else
			std::cout << this->_target << " hasn't been robotomized" << std::endl;	
	}
}

std::string	RobotomyRequestForm::getTarget(void) const {
	return (this->_target);
}
