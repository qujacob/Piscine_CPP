#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template<typename T>
class Array {

private:

	T				*_tab;
	unsigned int	_size;

public:

	Array(void) : _tab(NULL), _size(0) {}
	Array(unsigned int n) : _tab(new T[n]), _size(n) {}
	Array(Array	&a) : _tab(NULL) {*this = a;}
	~Array(void) {delete [] this->_tab;}

	Array	&operator=(Array &a) {
		this->_size = a.size();
		if (this->_tab != NULL)
			delete [] this->_tab;
		this->_tab = new T[a.size()];
		for (int i = 0; i < a.size(); i++)
			this->_tab[i] = a.getTabI(i);
		return (*this);
	}
	T	&operator[](int i) {
		if (i < 0 || static_cast<unsigned int>(i) >= this->_size)
			throw Array::BadIndexException();
		return (this->_tab[i]);
	}

	int	size(void) const {return (this->_size);}
	T	getTabI(int i) const {return (this->_tab[i]);}

	class BadIndexException : public std::exception {
		public:
			const char * what() const throw() {return ("bad index");}
	};

};

#endif