#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <exception>
#include <vector>
 
class PmergeMe {
	private:
		template<typename T>
		static void swap(T& a, T& b);

        static void mergeSort(std::vector< std::pair<int, int> >& arr, size_t start, size_t end);

        template<typename T>
        static size_t binarySearch(const T& arr, size_t start, size_t end, int target);

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& ref);
		~PmergeMe();

		PmergeMe&	operator=(const PmergeMe& ref);

        template<typename T>
        static T mergeInsertionSort(const T& arr, size_t start, size_t end);

};


template<typename T>
void PmergeMe::swap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
size_t PmergeMe::binarySearch(const T& arr, size_t start, size_t end, int target)
{
    if (end <= start)
        return end;

    size_t mid = start + (end - start) / 2;

    if (arr[mid] == target)
        return mid;
    else if (arr[mid] < target)
        return binarySearch(arr, mid + 1, end, target);
    else
        return binarySearch(arr, start, mid, target);
}

template<typename T>
T PmergeMe::mergeInsertionSort(const T& arr, size_t start, size_t end)
{
	size_t len = end - start;
	if (len < 2)
		return arr;
	int straggler = 0;
	if (len % 2)
		straggler = arr[end - 1];
	std::vector< std::pair<int, int> > splitArr(len / 2);
	size_t i = start, j = 0;
	for (; i + 1 < end; i += 2)
	{
		std::pair<int, int> tmpPair;
		if (arr[i] < arr[i + 1])
		{
			tmpPair.first = arr[i + 1];
            tmpPair.second = arr[i];
		}
		else
		{
			tmpPair.first = arr[i];
            tmpPair.second = arr[i + 1];
		}
		splitArr[j] = tmpPair;
		j++;
	}
	// splitArr 정렬시키기
	mergeSort(splitArr, 0, len / 2);
	// splitArr 출력
	// for (i = 0; i < len / 2; i++)
	// {
	// 	std::cout << "splitArr[" << i << "]: ";
	// 	std::cout << splitArr[i].first << " " << splitArr[i].second << std::endl;
	// }
	// splitArr 합치기
	T result;
	T pend;
	for (i = 0; i < len / 2; i++)
	{
		result.push_back(splitArr[i].first);
        pend.push_back(splitArr[i].second);
	}
	result.insert(result.begin(), pend[0]);
	// result에 pend 합치기(jacobsthal number)
	size_t jacob1 = 1;
	size_t jacob2 = 1;
	size_t insertPoint;
	size_t pendSize = pend.size();
	i = 0;
	while (i < pendSize)
	{
		if (i == jacob1 - 1)
		{
			if (jacob2 >= pendSize)
				break;
			size_t tmp = jacob2;
			jacob2 = jacob2 + (jacob1 * 2);
			jacob1 = tmp;
			if (jacob2 > pendSize)
				i = pendSize - 1;
			else
				i = jacob2 - 1;
		}
		insertPoint = binarySearch(result, 0, result.size(), pend[i]);
		result.insert(result.begin() + insertPoint, pend[i]);
		i--;
	}
	if (straggler)
	{
		insertPoint = binarySearch(result, 0, result.size(), straggler);
		result.insert(result.begin() + insertPoint, straggler);
	}
	return result;
}

#endif
