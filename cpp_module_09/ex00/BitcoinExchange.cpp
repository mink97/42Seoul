#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &ref) {*this = ref;}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange&	BitcoinExchange::operator=(BitcoinExchange const &ref)
{
	if (this != &ref) {
		*this = ref;
	}
	return (*this);
}

int BitcoinExchange::checkDate(const std::string& date)
{
	struct tm t;
	if (!strptime(date.c_str(), "%Y-%m-%d", &t))
		throw std::runtime_error("Error: invalid date");
	int year = t.tm_year + 1900;
	int month = t.tm_mon + 1;
	int day = t.tm_mday;
	int	days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
		days[1] = 29;
	if (day < 1 || day > days[t.tm_mon])
		throw std::runtime_error("Error: invalid date");
	return (year * 10000 + month * 100 + day);
}

void BitcoinExchange::getData(const std::string& arg, std::map<int, float>& data)
{
	char* endPoint;
	std::ifstream in(arg);
	if (!in.is_open())
		throw std::runtime_error("Error: could not open first data file");
	std::string line;
	std::getline(in, line);
	std::string::size_type pos = line.find(",");
	if (pos == std::string::npos || line.substr(0, pos) != "date" || line.substr(pos + 1) != "exchange_rate")
		throw BadInputException();
	while (std::getline(in, line))
	{
		pos = line.find(",");
		if (pos == std::string::npos)
			throw BadInputException();
		int date = checkDate(line.substr(0, pos));
		float exRate = static_cast<float>(std::strtod(line.substr(pos + 1).c_str(), &endPoint));
		// std::cout << "exRate : " << exRate << std::endl;
		data[date] = exRate;
	}
}

void BitcoinExchange::decreaseDate(int& date)
{
	int year = date / 10000;
	int month = date / 100 % 100;
	int day = date % 100;
	int	days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
		days[1] = 29;
	if (day != 1)
	{
		date--;
	}
	else if (month != 1)
	{
		date -= 100;
		date += days[month - 2] - 1;
	}
	else
	{
		date -= 10000;
		date += 1100;
		date += 30;
	}
}

void BitcoinExchange::getValue(const std::string& line, std::map<int, float>& data)
{
	char* endpoint;
	std::string::size_type pos = line.find("|");
	if (pos == std::string::npos)
		throw BadInputException();
	int date = BitcoinExchange::checkDate(line.substr(0, pos));
	double value = strtod(line.substr(pos + 1).c_str(), &endpoint);
	if (value <= 0)
		throw std::runtime_error("Error: not a positive number.");
	else if (value >= 1000)
		throw std::runtime_error("Error: too large a number.");
	if (date < 20090102 || date > 20220329)
		throw std::runtime_error("Error: out of date");
	std::cout << date / 10000 << "-" << (date / 100 % 100) / 10 << date / 100 % 10 << "-" \
		<< date % 100 / 10 << date % 10 << " => " << value << " = ";
	while (data.find(date) == data.end())
	{
		decreaseDate(date);
	}
	std::cout << data[date] * value << std::endl;
}

const char* BitcoinExchange::BadInputException::what() const throw()
{
	return ("Error: bad input");
}

