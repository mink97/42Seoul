#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <ctime>
#include <string>
#include <fstream>
#include <exception>

class BitcoinExchange
{
	private:
		// static std::map<int, float> data;
		static void decreaseDate(int& date);

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& ref);
		~BitcoinExchange();

		BitcoinExchange&	operator=(const BitcoinExchange& ref);

		static int checkDate(const std::string& date);
		static void getData(const std::string& arg, std::map<int, float>& data);
		static void getValue(const std::string& line, std::map<int, float>& data);

		class BadInputException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

#endif
