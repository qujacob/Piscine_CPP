#ifndef DATA_CPP
# define DATA_CPP

#include <iostream>

class Data {

private:

	int	_x;
	int _y;

public:

	Data(void);
	Data(Data &d);
	~Data(void);

	Data	&operator=(Data &d);

	int	getX(void) const;
	int	getY(void) const;

};

uintptr_t	serialize(Data *ptr);

Data		*deserialize(uintptr_t raw);

#endif