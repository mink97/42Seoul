#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <exception>
#include <algorithm>

template<typename T>
typename T::iterator easyfind(T container, int num)
{
	typename T::iterator iter = std::find(container.begin(), container.end(), num);
	if (iter == container.end())
	{
		throw std::runtime_error("failed to find the value.");
	}
	return (iter);
}

#endif
