#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
	private:

	public:
		MutantStack();
		MutantStack(const MutantStack& ref);
		~MutantStack();

		MutantStack&	operator=(const MutantStack& ref);

		typedef typename MutantStack<T>::stack::container_type::iterator iterator;
		typedef typename MutantStack<T>::stack::container_type::const_iterator const_iterator;
		typedef typename MutantStack<T>::stack::container_type::reverse_iterator reverse_iterator;
		typedef typename MutantStack<T>::stack::container_type::const_reverse_iterator const_reverse_iterator;
		iterator begin();
		iterator end();
		const_iterator cbegin();
		const_iterator cend();
		reverse_iterator rbegin();
		reverse_iterator rend();
		const_reverse_iterator crbegin();
		const_reverse_iterator crend();
};

template<typename T>
MutantStack<T>::MutantStack() {}

template<typename T>
MutantStack<T>::MutantStack(MutantStack const &ref) : std::stack<T>(ref) {}

template<typename T>
MutantStack<T>::~MutantStack() {}

template<typename T>
MutantStack<T>&	MutantStack<T>::operator=(MutantStack<T> const &ref)
{
	if (this != &ref) {
		std::stack<T>::operator=(ref);
	}
	return (*this);
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return (this->c.begin());
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return (this->c.end());
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::cbegin()
{
	return (this->c.cbegin());
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::cend()
{
	return (this->c.cend());

}

template<typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin()
{
	return (this->c.rbegin());
}

template<typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend()
{
	return (this->c.rend());
}

template<typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::crbegin()
{
	return (this->c.crbegin());
}

template<typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::crend()
{
	return (this->c.crend());
}

#endif
