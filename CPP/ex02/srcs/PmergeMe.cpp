#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(int *numbers, int size) {
	for (int i = 0; i < size; i++) {
		_vect.push_back(numbers[i]);
		_deque.push_back(numbers[i]);
	}
}

PmergeMe::PmergeMe(PmergeMe &other) {
	_vect = other.getVector();
	_deque = other.getDeque();
}

PmergeMe::~PmergeMe() {}

PmergeMe			&PmergeMe::operator=(PmergeMe &other) {
	_vect = other.getVector();
	_deque = other.getDeque();
	return (*this);
}

void				PmergeMe::vectSort() {
	const clock_t begin_time = clock();

	if (_vect.size() != 1)
		_sort(_vect, 0, _vect.size() - 1);

	_vect_time = static_cast<float>(clock () - begin_time) / 1000;
}

void				PmergeMe::dequeSort() {
	const clock_t begin_time = clock();
	
	if (_deque.size() != 1)
		_sort(_deque, 0, _deque.size() - 1);

	_deque_time = static_cast<float>(clock () - begin_time) / 1000;
}

std::vector<int>	&PmergeMe::getVector() { return (_vect); }

std::deque<int>		&PmergeMe::getDeque() { return (_deque); }

float				PmergeMe::getVectTime() const { return (_vect_time); }

float				PmergeMe::getDequeTime() const { return (_deque_time); }
	
template<class T>
void				PmergeMe::_sort(T &c, int p, int r) {
	if (r - p > 5) {
		int q = (p + r) / 2;
		_sort(c, p, q);
		_sort(c, q + 1, r);
		_merge(c, p, q, r);
	}
	else
		_insert(c, p, r);
}

template<class T>
void				PmergeMe::_merge(T &c, int p, int q, int r) {
	int n1 = q - p + 1;
	int n2 = r - q;
	T	LA(n1), RA(n2);
	for (int i = 0; i < n1; i++)
		LA[i] = c[p + i];
	for (int i = 0; i < n2; i++)
		RA[i] = c[q + 1 + i];
	int RIDX = 0;
	int LIDX = 0;
	for (int i = p; i <= r; i++) {
		if (RIDX == n2)
			c[i] = LA[LIDX++];
		else if (LIDX == n1)
			c[i]= RA[RIDX++];
		else if (RA[RIDX] > LA[LIDX])
			c[i] = LA[LIDX++];
		else
			c[i] = RA[RIDX++];
	}
}

template<class T>
void				PmergeMe::_insert(T &c, int p, int r) {
	for (int i = p; i < r; i++) {
		int tempVal = c[i + 1];
		int j = i + 1;
		while (j > p && c[j - 1] > tempVal) {
			c[j] = c[j - 1];
			j--;
		}
		c[j] = tempVal;
	}
}
