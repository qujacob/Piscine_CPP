#pragma once

#include <stack>
#include <iostream>

class RPN {

public:

	RPN();
	RPN(RPN &other);
	~RPN();

	RPN &operator=(RPN &other);

	std::stack<int>	&getStack(void);
	size_t			size(void) const;
	void			pop(void);
	void			push(int n);
	int				&top(void);

private:

	std::stack<int>	_stack;

};