#include <string>
#include <vector>
#include <deque>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "PmergeMe.hpp"

int myStoi(std::string str)
{
	long long num = 0;
	size_t len = str.size();
	if (len > 10)
		throw std::runtime_error("Error");
	for (size_t i = 0; i < str.size(); i++)
	{
		if (i == 0 && str[i] == '+' && len > 1)
			continue;
		if (str[i] < '0' || str[i] > '9')
			throw std::runtime_error("Error");
		num = num * 10 + str[i] - '0';
		if (num > 2147483647)
			throw std::runtime_error("Error");
	}
	if (num == 0)
		throw std::runtime_error("Error");
	return static_cast<int>(num);
}

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		std::cout << "Error" << std::endl;
		return (1);
	}
	std::vector<int> vec;
	std::deque<int> deq;
	try
	{
		for (int i = 1; i < argc; i++)
		{
			int n = myStoi(argv[i]);
			vec.push_back(n);
			deq.push_back(n);
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (1);
	}
	std::cout << "Before:  ";
	for (std::vector<int>::iterator itr = vec.begin(); itr != vec.end(); itr++)
	{
		std::cout << *itr << " ";
	}
	std::cout << "\nAfter:   ";
	std::vector<int> sortedVec = PmergeMe::mergeInsertionSort(vec, 0, vec.size());
	for (std::vector<int>::iterator itr = sortedVec.begin(); itr != sortedVec.end(); itr++)
	{
		std::cout << *itr << " ";
	}
	// clock_gettime 이용
	struct timespec start, finish;
	std::cout << "\nTime to process a range of " << argc - 1;
	std::cout << " elements with std::vector : ";
	clock_gettime(CLOCK_MONOTONIC, &start);
	PmergeMe::mergeInsertionSort(vec, 0, vec.size());
	clock_gettime(CLOCK_MONOTONIC, &finish);
	std::cout << (finish.tv_sec - start.tv_sec) * 1000000.0 + (finish.tv_nsec - start.tv_nsec) / 1000.0 << " us" << std::endl;
	std::cout << "Time to process a range of " << argc - 1;
	std::cout << " elements with std::deque : ";
	clock_gettime(CLOCK_MONOTONIC, &start);
	PmergeMe::mergeInsertionSort(deq, 0, deq.size());
	clock_gettime(CLOCK_MONOTONIC, &finish);
	std::cout << (finish.tv_sec - start.tv_sec) * 1000000.0 + (finish.tv_nsec - start.tv_nsec) / 1000.0 << " us" << std::endl;
	// clock_t 이용
	// clock_t start, finish;
	// std::cout << "\nTime to process a range of " << argc - 1;
	// std::cout << " elements with std::vector : ";
	// start = std::clock();
	// PmergeMe::mergeInsertionSort(vec, 0, vec.size());
	// finish = std::clock();
	// std::cout << static_cast<double>(finish - start) << " us" << std::endl;
	// std::cout << "Time to process a range of " << argc - 1;
	// std::cout << " elements with std::deque : ";
	// start = std::clock();
	// PmergeMe::mergeInsertionSort(deq, 0, deq.size());
	// finish = std::clock();
	// std::cout << static_cast<double>(finish - start) << " us" << std::endl;
}
