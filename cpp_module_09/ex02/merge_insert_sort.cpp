#include <iostream>
#include <string>
#include <vector>
#include <deque>

template<typename T>
void swap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
void insertionSort(T& arr, size_t start, size_t end)
{
	for (int i = start; i < end; i++)
	{
		for (int j = i; j > start; j--)
		{
			if (arr[j] > arr[j - 1])
				break;
			swap(arr[j], arr[j - 1]);
		}
	}
}

template<typename T>
void merge(T& arr, size_t start, size_t end)
{
	T tmp = arr;
	size_t mid = (start + end) / 2;
	int i = start, j = mid, k = start;
	while (i < mid && j < end)
	{
		if (tmp[i] < tmp[j])
		{
			arr[k] = tmp[i];
			i++;
		}
		else
		{
			arr[k] = tmp[j];
			j++;
		}
		k++;
	}
	while (i < mid)
	{
		arr[k] = tmp[i];
		i++;
		k++;
	}
	while (j < end)
	{
		arr[k] = tmp[j];
		j++;
		k++;
	}
}

template<typename T>
void mergeSort(T& arr, size_t start, size_t end)
{
	if (end - start > 1)
	{
		size_t mid = (start + end) / 2;
		mergeSort(arr, start, mid);
		mergeSort(arr, mid, end);
		merge(arr, start, end);
	}
}

template<typename T>
void mergeInsertionSort(T& arr, size_t start, size_t end)
{
	if (end - start < 10)
		insertionSort(arr, start, end);
	else
	{
		size_t mid = (start + end) / 2;
		mergeInsertionSort(arr, start, mid);
		mergeInsertionSort(arr, mid, end);
		merge(arr, start, end);
	}
}

template<typename T>
void printArr(const T& arr)
{
	for (typename T::const_iterator itr = arr.begin(); itr != arr.end(); itr++)
	{
		std::cout << *itr << " ";
	}
	std::cout << std::endl;
}

int main()
{
	std::vector<int> vec = {3, 5, 9, 7, 4, 11, 23, 2345, 215, 3456, 456, 253, 124, 234, 342};
	std::vector<int> vec2 = {1};
	std::deque<int> deq = {3, 5, 9, 7, 4, 11, 23, 2345, 215, 3456, 456, 253, 124, 234, 342};

	printArr(vec2);
	mergeSort(vec2, 0, vec2.size());
	printArr(vec2);
	printArr(vec);
	printArr(deq);
	mergeInsertionSort(vec, 0, vec.size());
	mergeInsertionSort(deq, 0, deq.size());
	
	printArr(vec);
	printArr(deq);
}
