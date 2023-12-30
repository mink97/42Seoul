#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template<typename T>
class Array {
	private:
		T* _arr;
		unsigned int _size;

	public:
		Array();
		Array(unsigned int n);
		Array(const Array& ref);
		~Array();

		Array&	operator=(const Array& ref);

		unsigned int size() const;

		T& operator[](unsigned int idx);
		const T& operator[](unsigned int idx) const;

		class IndexException : public std::exception
		{
		public:
			const char* what() const throw();
		};
		
};

template<typename T>
Array<T>::Array() : _arr(NULL), _size(0)
{
	_arr = new T[0];
}

template<typename T>
Array<T>::Array(unsigned int n) : _arr(NULL), _size(n)
{
	_arr = new T[n];
}

template<typename T>
Array<T>::Array(const Array& ref) : _arr(NULL), _size(ref._size)
{
	_arr = new T[_size];
	for (unsigned int i = 0; i < _size; i++)
	{
		_arr[i] = ref._arr[i];
	}
}

template<typename T>
Array<T>::~Array()
{
	if (_arr)
		delete[] _arr;
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& ref)
{
	if (this != &ref)
	{
		if (_arr)
			delete[] _arr;
		_size = ref._size;
		_arr = new T[_size];
		for (int i = 0; i < _size; i++)
			_arr[i] = ref._arr[i];
	}
	return (*this);
}

template<typename T>
unsigned int Array<T>::size() const
{
	return (_size);
}

template<typename T>
T& Array<T>::operator[](unsigned int idx)
{
	if (size() <= idx)
		throw IndexException();
	return (_arr[idx]);
}

template<typename T>
const T& Array<T>::operator[](unsigned int idx) const
{
	if (size() <= idx)
		throw IndexException();
	return (_arr[idx]);
}

template<typename T>
const char* Array<T>::IndexException::what() const throw()
{
	return ("its index is out of bounds");
}

#endif
