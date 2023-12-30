#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &ref)
{
	*this = ref;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter&	ScalarConverter::operator=(ScalarConverter const &ref)
{
	if (this != &ref)
		*this = ref;
	return (*this);
}

void ScalarConverter::convert(const std::string& argv)
{
	double value;
	char* endPoint;
	bool isError = false;
	if (argv.size() == 1 && !std::isdigit(argv[0]))
		value = static_cast<double>(argv[0]);
	else
		value = strtod(argv.c_str(), &endPoint);
	// if (argv.size() != 1 && argv == endPoint)
	// {
	// 	std::cout << "invalid argv!" << std::endl;
	// 	return ;
	// }
	// std::cout << "value : " << value << std::endl;
	if (std::isnan(value) || std::isinf(value))
		isError = true;
	/*
	* tochar
	* 1. 문자 하나만 왔는가?
	* 2. isprint되는가?
	*/
	if (isError)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(value) || value != static_cast<int>(value))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;

	/*
	* toint
	* 1. min, max 값 넘어가면 impossible로 표현하자
	* 2. int형은 intinity 안가지고 있음.
	*/
	std::cout << "int: ";
	if (isError || value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(value) << std::endl;

	/*
	* tofloat
	* 1. 정수형이면 .0f, 아니면 f 붙이기
	* 2. 6자리 넘어가면 과학적 표기법 -> 그냥 f만 붙이기
	*/
	std::cout << "float: ";
	if (isError)
		std::cout << std::showpos << value << 'f' << std::endl;
	else if (value > std::numeric_limits<float>::max())
		std::cout << "inff" << std::endl;
	else if (value < std::numeric_limits<float>::max() * -1)
		std::cout << "-inff" << std::endl;
	else
	{
		std::string tmp = std::to_string(value);
		int i = tmp.find('.') != std::string::npos ? tmp.find('.') : tmp.size();
		if (i > 6 || value != static_cast<int>(value))
			std::cout << static_cast<float>(value) << "f" << std::endl;
		else
			std::cout << static_cast<float>(value) << ".0f" << std::endl;
	}

	/*
	* todouble
	* 1. 정수형이면 뒤에 .0 추가
	* 2. 6자리 넘어가면 과학적 표기법 -> .0 붙이면 x
	*/
	std::cout << "double: ";
	if (isError)
		std::cout << std::showpos << value << std::endl;
	else
	{
		std::string tmp = std::to_string(value);
		int i = tmp.find('.') != std::string::npos ? tmp.find('.') : tmp.size();
		if (i > 6 || value != static_cast<int>(value))
			std::cout << static_cast<double>(value) << std::endl;
		else
			std::cout << static_cast<double>(value) << ".0" << std::endl;
	}

}
