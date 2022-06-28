#include "Harl.hpp"

Harl::Harl(void) {

}

Harl::~Harl(void) {

}

void	Harl::complain(std::string level) {
	func	funcs[4] = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};
	std::string	levels[4] = {"debug", "info", "warning", "error"};

	for (int i = 0; i < 4; i++) {
		if (!level.compare(levels[i]))
			((this)->*funcs[i])();
	}
}

void	Harl::_debug(void) {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << std::endl;
}

void	Harl::_info(void) {
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::_warning(void) {
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl << "I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::_error(void) {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
