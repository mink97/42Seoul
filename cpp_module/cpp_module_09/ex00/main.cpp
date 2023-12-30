#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2 && argc != 3)
	{
		std::cout << "Error: could not open file." << std::endl;
		return (1);
	}

	std::string arg;
	if (argc == 2)
		arg = "data.csv";
	else
		arg = argv[2];
	std::map<int, float> data;
	try
	{
		BitcoinExchange::getData(arg, data);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
		return (1);
	}

	std::ifstream input(argv[1]);
	if (!input.is_open())
	{
		std::cout << "Error: could not open file." << std::endl;
		return (1);
	}
	std::string line;
	std::getline(input, line);
	if (line != "date | value")
	{
		std::cout << "Error: invalid file." << std::endl;
		return (1);
	}
	while (std::getline(input, line))
	{
		try
		{
			BitcoinExchange::getValue(line, data);
		}
		catch(const BitcoinExchange::BadInputException& e)
		{
			std::cout << e.what() << " => " << line << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
	}
}
