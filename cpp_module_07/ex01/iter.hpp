#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T , typename FUNC>
void iter(T* arr, std::size_t len, FUNC func)
{
	for (std::size_t i = 0; i < len; i++)
	{
		std::cout << i+1 << " : ";
		func(arr[i]);
	}
}

template<typename T>
void ft_print(T& arg)
{
	std::cout << arg << std::endl;
}

#endif
