#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <iterator>

template<typename T>
class MutantStack : public std::stack<T> {

private :


public :

	MutantStack(void) {};
	MutantStack(MutantStack &ms) {*this = ms;};
	virtual ~MutantStack(void) {};

	MutantStack<T>	&operator=(MutantStack<T> &ms) {
		std::stack<T>::operator=(ms);
		return (*this);
	};

	typedef typename std::stack<T>::container_type::iterator iterator;

	iterator	begin(void) {return (this->c.begin());};
	iterator	end(void) {return (this->c.end());};

};

#endif