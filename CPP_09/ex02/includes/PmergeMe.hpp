#pragma once

#include <iostream>
#include <cstdlib>
#include <cctype>
#include <ctime>
#include <vector>
#include <deque>
#include <iomanip>

class PmergeMe {

public:

	PmergeMe();
	PmergeMe(int *numbers, int size);
	PmergeMe(PmergeMe &other);
	~PmergeMe();

	PmergeMe	&operator=(PmergeMe &other);

	void				vectSort();
	void				dequeSort();


	std::vector<int>	&getVector();
	std::deque<int>		&getDeque();
	float				getVectTime() const;
	float				getDequeTime() const;

private:

	std::vector<int>	_vect;
	std::deque<int>		_deque;
	float				_vect_time;
	float				_deque_time;

	template<class T>
	void				_sort(T &c, int p, int r);
	template<class T>
	void				_merge(T &c, int p, int q, int r);
	template<class T>
	void				_insert(T &c, int p, int r);

};