#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(RPN &other) { *this = other; }

RPN::~RPN() {}

RPN				&RPN::operator=(RPN &other) {
	_stack = other.getStack();
	return (*this);
}

std::stack<int>	&RPN::getStack(void) { return (_stack); }

size_t			RPN::size(void) const { return (_stack.size()); }

void			RPN::pop(void) { _stack.pop(); }

void			RPN::push(int n) { _stack.push(n); }

int				&RPN::top(void) { return _stack.top(); }