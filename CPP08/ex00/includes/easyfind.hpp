#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <map>

class NotInConstructorException : public std::exception {
public:
	const char * what() const throw() {
		return ("Not in constructor");
	}
};

template<typename T>
typename T::iterator	easyfind(T &t, int n) {
	typename T::iterator it = std::find(t.begin(), t.end(), n);
	if (it == t.end())
		throw NotInConstructorException();
	return (it);
}

#endif