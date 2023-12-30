#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template<typename T>
void swap(T& arg1, T& arg2)
{
	T tmp = arg1;
	arg1 = arg2;
	arg2 = tmp;
}

template<typename T>
const T& min(const T& a, const T& b)
{
	return (a < b ? a : b);
}

template<typename T>
const T& max(const T& a, const T& b)
{
	return (a > b ? a : b);
}

#endif
