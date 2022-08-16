#include "Span.hpp"

// Constructors & Destructors

Span::Span(void) : _N(5) {}

Span::Span(const int N) : _N(N) {}

Span::Span(Span &sp) {*this = sp;}

Span::~Span(void) {}

// Operators

Span	&Span::operator=(Span &sp) {
	this->_N = sp.getN();
	this->_l = sp.getL();
	return (*this);
}

// Getters & Setters

int				Span::getN(void) const {return (this->_N);}

std::vector<int>	Span::getL(void) const {return (this->_l);}

// Methods

void	Span::addNumber(const int n) {
	if (static_cast<int>(this->_l.size()) < this->_N)
		this->_l.push_back(n); 
}

int		Span::shortestSpan(void) const {
	if (this->_l.size() < 2)
		throw Span::SpanSize();
	int	span = INT_MAX;
	std::vector<int>::const_iterator i = this->_l.begin(), j;
	while (i != this->_l.end()) {
		j = i + 1;
		while (j != this->_l.end()) {
			if (std::abs(*j - *i) < span)
				span = std::abs(*j - *i);
			j++;
		}
		i++;
	}
	return (span);
}	

int		Span::longestSpan(void) const {
	if (this->_l.size() < 2)
		throw Span::SpanSize();
	std::vector<int>::const_iterator	min = std::min_element(this->_l.begin(), this->_l.end());
	std::vector<int>::const_iterator	max = std::max_element(this->_l.begin(), this->_l.end());
	return (*max - *min);
}
