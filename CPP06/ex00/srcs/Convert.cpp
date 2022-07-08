#include "Convert.hpp"

// PUBLIC

Convert::Convert(void) : _arg(NULL), _argChar(0), _argInt(0), _argFloat(0), _argDouble(0), _charIsDisp(true) {}

Convert::Convert(Convert &c) {*this = c;}

Convert::Convert(std::string arg) : _arg(arg), _argChar(0), _argInt(0), _argFloat(0), _argDouble(0), _charIsDisp(true) {}

Convert::~Convert(void) {}

Convert	&Convert::operator=(Convert &c) {
	this->_arg = c.getArg();
	this->_argChar = c.getChar();
	this->_argInt = c.getInt();
	this->_argFloat = c.getFloat();
	this->_argDouble = c.getDouble();
	this->_charIsDisp = c.getCharIsDisp();
	return (*this);
}

e_types	Convert::whatType(void) {
	if (_isChar(this->_arg))
		return (CHAR);
	else if (_isInt(this->_arg))
		return (INT);
	else if (_isFloat(this->_arg))
		return (FLOAT);
	else if (_isDouble(this->_arg))
		return (DOUBLE);
	return (NONE);
}

void	Convert::print(e_types type) {
	switch (type) {
		case CHAR :
			std::cout << "char: " << this->_argChar << std::endl;
			std::cout << "int: " << static_cast<int>(this->_argChar) << std::endl;
			std::cout << "float: " << static_cast<float>(this->_argChar) << ".0f" << std::endl;
			std::cout << "double: " << static_cast<double>(this->_argChar) << ".0" << std::endl;
			break ;
		case INT :
			std::cout << "char: " << static_cast<char>(this->_argInt) << std::endl;
			std::cout << "int: " << this->_argInt << std::endl;
			std::cout << "float: " << static_cast<float>(this->_argInt) << ".0f" << std::endl;
			std::cout << "double: " << static_cast<double>(this->_argInt) << ".0" << std::endl;
			break ;
		case FLOAT :
			std::cout << "char: " << "impossible" << std::endl;
			std::cout << "int: " << "impossible" << std::endl;
			if (this->_arg == "-inff" || this->_arg == "+inff" || this->_arg == "nanf")
				std::cout << "float: " << this->_arg << std::endl;
			else
				std::cout << "float: " << this->_argDouble << std::endl;		
			if (this->_arg == "-inff" || this->_arg == "+inff" || this->_arg == "nanf")
				std::cout << "double: " << this->_arg.substr(0, this->_arg.size() - 1) << std::endl;
			else
				std::cout << "double: " << this->_argDouble << std::endl;
			break ;
		case DOUBLE :
			std::cout << "char: " << "impossible" << std::endl;
			std::cout << "int: " << "impossible" << std::endl;
			if (this->_arg == "-inf" || this->_arg == "+inf" || this->_arg == "nan")
				std::cout << "float: " << this->_arg << "f" << std::endl;
			else
				std::cout << "float: " << static_cast<float>(this->_argDouble) << "f" << std::endl;		
			if (this->_arg == "-inf" || this->_arg == "+inf" || this->_arg == "nan")
				std::cout << "double: " << this->_arg << std::endl;
			else
				std::cout << "double: " << this->_argDouble << std::endl;
			break ;
		default :
			std::cout << "bite" << std::endl;
	}
}

std::string	Convert::getArg(void) const {return (this->_arg);}

char		Convert::getChar(void) const {return (this->_argChar);}

int			Convert::getInt(void) const {return (this->_argInt);}

float		Convert::getFloat(void) const {return (this->_argFloat);}

double		Convert::getDouble(void) const {return (this->_argDouble);}

bool		Convert::getCharIsDisp(void) const {return (this->_charIsDisp);}

// PRIVATE

bool	Convert::_isChar(std::string str) {
	if (str.size() == 1 && !std::isdigit(str[0]))
	{
		this->_argChar = str[0];
		return (true);
	}
	return (false);
}

bool	Convert::_isInt(std::string str) {
	unsigned long i = 0;

	if (str[0] == '-')
		i++;
	for (; i < str.size(); i++)
		if (!std::isdigit(str[i]))
			return (false);
	this->_argInt = std::strtol(str.c_str(), NULL, 10);
	return (true);
}

bool	Convert::_isFloat(std::string str) {
	if (str == "-inff" || str == "+inff" || str == "nanf")
		return (true);
	unsigned long i = 0;
	if (str[0] == '-')
		i++;
	for (; i < str.size() - 1; i++) {
		if (!std::isdigit(str[i]) && str[i] != '.')
			return (false);
	}
	if (str[i] != 'f')
		return (false);
	this->_argFloat = std::strtof(str.c_str(), NULL);
	return (true);
}

bool	Convert::_isDouble(std::string str) {
	if (str == "-inf" || str == "+inf" || str == "nan")
		return (true);
	unsigned long i = 0;
	if (str[0] == '-')
		i++;
	for (; i < str.size() - 1; i++) {
		if (!std::isdigit(str[i]) && str[i] != '.')
			return (false);
	}
	if (str[i] == 'f')
		return (false);
	this->_argDouble = std::strtod(str.c_str(), NULL);
	return (true);
}