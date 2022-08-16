#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

class	Span {

private :

	int				_N;
	std::vector<int>	_l;

public :

	Span(void);
	Span(const int N);
	Span(Span &sp);
	~Span(void);

	Span	&operator=(Span &sp);

	void				addNumber(const int n);
	int					shortestSpan(void) const;
	int					longestSpan(void) const;
	int					getN(void) const;
	std::vector<int>	getL(void) const;

	class SpanSize : public std::exception {
		public:
		const char * what() const throw() {return ("The span isn't big enough");}
	};

};
