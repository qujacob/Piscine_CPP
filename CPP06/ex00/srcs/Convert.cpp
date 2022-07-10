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
			std::cout << "char: " << "'" << this->_argChar << "'" << std::endl;
			std::cout << "int: " << this->_argInt << std::endl;
			std::cout << "float: " << this->_argFloat << ".0f" << std::endl;
			std::cout << "double: " << this->_argDouble << ".0" << std::endl;
			break ;
		case INT :
			if (this->_argChar == -1)
				std::cout << "char: " <<  "Non displayable" << std::endl;
			else
				std::cout << "char: " <<  "'" << this->_argChar <<  "'" << std::endl;
			std::cout << "int: " << this->_argInt << std::endl;
			std::cout << "float: " << this->_argFloat << ".0f" << std::endl;
			std::cout << "double: " << this->_argDouble << ".0" << std::endl;
			break ;
		case FLOAT :
			if (this->_argChar == -1)
				std::cout << "char: " <<  "Non displayable" << std::endl;
			else if (this->_argChar == -2)
				std::cout << "char: " <<  "impossible" << std::endl;
			else
				std::cout << "char: " <<  "'" << this->_argChar <<  "'" << std::endl;
			if (this->_arg == "-inff" || this->_arg == "+inff" || this->_arg == "nanf")
				std::cout << "int: " << "impossible" << std::endl;
			else
				std::cout << "int: " << this->_argInt << std::endl;
			std::cout << "float: " << this->_argFloat;
			if (this->_arg[this->_arg.size() - 3] == '.' && this->_arg[this->_arg.size() - 2] == '0')
				std::cout << ".0";
			std::cout << "f" << std::endl;		
			std::cout << "double: " << this->_argDouble;
			if (this->_arg[this->_arg.size() - 3] == '.' && this->_arg[this->_arg.size() - 2] == '0')
				std::cout << ".0";
			std::cout << std::endl;
			break ;
		case DOUBLE :
			if (this->_argChar == -1)
				std::cout << "char: " <<  "Non displayable" << std::endl;
			else if (this->_argChar == -2)
				std::cout << "char: " <<  "impossible" << std::endl;
			else
				std::cout << "char: " <<  "'" << this->_argChar <<  "'" << std::endl;
			if (this->_arg == "-inf" || this->_arg == "+inf" || this->_arg == "nan")
				std::cout << "int: " << "impossible" << std::endl;
			else
				std::cout << "int: " << this->_argInt << std::endl;
			std::cout << "float: " << this->_argFloat;
			if (this->_arg[this->_arg.size() - 2] == '.' && this->_arg[this->_arg.size() - 1] == '0')
				std::cout << ".0";
			std::cout << "f" << std::endl;		
			std::cout << "double: " << this->_argDouble;
			if (this->_arg[this->_arg.size() - 2] == '.' && this->_arg[this->_arg.size() - 1] == '0')
				std::cout << ".0";
			std::cout << std::endl;
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
		this->_argInt = static_cast<int>(this->_argChar);
		this->_argFloat = static_cast<float>(this->_argChar);
		this->_argDouble = static_cast<double>(this->_argChar);
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
	if (this->_argInt < 32 || this->_argInt > 126)
		this->_argChar = -1;
	else
		this->_argChar = static_cast<char>(this->_argInt);
	this->_argFloat = static_cast<float>(this->_argInt);
	this->_argDouble = static_cast<double>(this->_argInt);
	return (true);
}

bool	Convert::_isFloat(std::string str) {
	if (str != "-inff" && str != "+inff" && str != "nanf") {
		unsigned long i = 0;
		if (str[0] == '-')
			i++;
		for (; i < str.size() - 1; i++) {
			if (!std::isdigit(str[i]) && str[i] != '.')
				return (false);
		}
		if (str[i] != 'f')
			return (false);
	}
	this->_argFloat = std::strtof(str.c_str(), NULL);
	this->_argInt = static_cast<int>(this->_argFloat);
	if (str[str.size() - 3] == '.' && str[str.size() - 2] == '0' && str[str.size() - 1] == 'f') {
		if (this->_argInt >= 32 && this->_argInt <= 126)
			this->_argChar = static_cast<char>(this->_argFloat);
		else
			this->_argChar = -1;
	}
	else
		this->_argChar = -2;
	this->_argDouble = static_cast<double>(this->_argFloat);
	return (true);
}

bool	Convert::_isDouble(std::string str) {
	if (str != "-inf" && str != "+inf" && str != "nan") {
		unsigned long i = 0;
		if (str[0] == '-')
			i++;
		for (; i < str.size() - 1; i++) {
			if (!std::isdigit(str[i]) && str[i] != '.')
				return (false);
		}
		if (str[i] == 'f')
			return (false);
	}
	this->_argDouble = std::strtod(str.c_str(), NULL);
	this->_argInt = static_cast<int>(this->_argDouble);
	if (str[str.size() - 2] == '.' && str[str.size() - 1] == '0') {
		if (this->_argInt >= 32 && this->_argInt <= 126)
			this->_argChar = static_cast<char>(this->_argDouble);
		else
			this->_argChar = -1;
	}
	else
		this->_argChar = -2;
	this->_argFloat = static_cast<float>(this->_argDouble);
	return (true);
}