#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template<typename T>
void	iter(T *tab, int size, void (*f)(T));

template<typename T>
void	increment(T &elem);

template<typename T>
void	setZero(T &elem);

#endif