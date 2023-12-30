#include "iter.hpp"
#include <string>

int main()
{
	int arr1[10] = {1 , 23, 35, 2346, 2354, 234, 45, 6785, 675, 234};

	::iter(arr1, 10, ::ft_print<int>);

	std::string strArr[5] = {"as", " ming", "kang", "min", "gwan"};
	::iter(strArr, 5, ::ft_print<std::string>);

}
