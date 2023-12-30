#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <exception>

class Span {
	private:
		std::vector<int> _vec;
		unsigned int _capacity;
		Span();

	public:
		Span(unsigned int N);
		Span(const Span& ref);
		~Span();

		Span&	operator=(const Span& ref);

		void addNumber(int num);
		void addRange(int num);
		unsigned int shortestSpan();
		unsigned int longestSpan();

		class MaxStoreException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class NoSpanException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

#endif
