#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& ref) {*this = ref;}

PmergeMe::~PmergeMe() {}

PmergeMe&	PmergeMe::operator=(const PmergeMe& ref) {
	if (this != &ref) {
		*this = ref;
	}
	return (*this);
}

void PmergeMe::mergeSort(std::vector< std::pair<int, int> >& arr, size_t start, size_t end)
{
    if (end - start > 1)
    {
        size_t mid = start + (end - start) / 2;

        // 왼쪽과 오른쪽 반을 정렬합니다.
        mergeSort(arr, start, mid);
        mergeSort(arr, mid, end);

        std::vector< std::pair<int, int> > merged(end - start);

        size_t i = start, j = mid, k = 0;
        while (i < mid && j < end)
        {
            if (arr[i].first < arr[j].first)
            {
                merged[k] = arr[i];
                i++;
            }
            else
            {
                merged[k] = arr[j];
                j++;
            }
            k++;
        }

        while (i < mid)
        {
            merged[k] = arr[i];
            i++;
            k++;
        }

        while (j < end)
        {
            merged[k] = arr[j];
            j++;
            k++;
        }

        // 정렬된 merged를 원래 배열 arr에 복사합니다.
        for (k = 0, i = start; i < end; i++, k++)
        {
            arr[i] = merged[k];
        }
    }
}