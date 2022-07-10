#include "Data.hpp"

Data::Data(void) : _x(0), _y(0) {}

Data::Data(Data &d) : _x(d.getX()), _y(d.getY()) {}

Data::~Data(void) {}

Data	&Data::operator=(Data &d) {
	this->_x = d.getX();
	this->_y = d.getY();
	return (*this);
}

int		Data::getX(void) const {return (this->_x);}

int		Data::getY(void) const {return (this->_y);}

uintptr_t	serialize(Data *ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data		*deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data*>(raw));
}