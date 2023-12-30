#include <iostream>
#include <string>
#include <limits>
#include <iomanip>

int main()
{
	char* point;
	double val = std::strtod("123415.123", &point);

	std::cout << (float)3.3 << std::endl;
	// std::cout.unsetf(std::ios::fixed);
	std::cout << std::showpos << static_cast<float>(val) << std::endl;
}


// numeric_limits example
// #include <iostream>     // std::cout
// #include <limits>       // std::numeric_limits

// int main () {
//   std::cout << std::boolalpha;
//   std::cout << "Minimum value for int: " << std::numeric_limits<int>::min() << '\n';
//   std::cout << "Maximum value for int: " << std::numeric_limits<int>::max() << '\n';
//   std::cout << "int is signed: " << std::numeric_limits<int>::is_signed << '\n';
//   std::cout << "Non-sign bits in int: " << std::numeric_limits<int>::digits << '\n';
//   std::cout << "float has infinity: " << std::numeric_limits<float>::has_infinity << '\n';
//   std::cout << "float has nan: " << std::numeric_limits<float>::has_quiet_NaN << '\n';
//   std::cout << "int has nan: " << std::numeric_limits<float>::has_signaling_NaN << '\n';
//   return 0;
// }
