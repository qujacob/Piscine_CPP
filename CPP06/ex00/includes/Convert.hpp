#ifndef CONVERT_HPP
# define CONVERT_HPP

#include <iostream>
#include <limits>

enum	e_types {
	NONE,
	CHAR,
	INT,
	FLOAT,
	DOUBLE
};

class Convert {

private:

	std::string	_arg;
	char		_argChar;
	int			_argInt;
	float		_argFloat;
	double		_argDouble;
	bool		_charIsDisp;

	bool	_isChar(std::string str);
	bool	_isInt(std::string str);
	bool	_isFloat(std::string str);
	bool	_isDouble(std::string str);

public:

	Convert(void);
	Convert(Convert &c);
	Convert(std::string arg);
	~Convert(void);

	Convert	&operator=(Convert &c);

	e_types	whatType(void);
	void	print(e_types type);

	std::string	getArg(void) const;
	char		getChar(void) const;
	int			getInt(void) const;
	float		getFloat(void) const;
	double		getDouble(void) const;
	bool		getCharIsDisp(void) const;

};

#endif