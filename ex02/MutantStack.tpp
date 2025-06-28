/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 21:03:35 by athonda           #+#    #+#             */
/*   Updated: 2025/06/28 23:33:42 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>

template <class T>
MutantStack<T>::MutantStack() :
	_stack()
{}

template <class T>
MutantStack<T>::MutantStack(MutantStack const &other) :
	_stack(other._stack)
{}

template <class T>
MutantStack<T>	&MutantStack<T>::operator=(MutantStack const &other)
{
	if (this != &other)
	{
		this->_stack = other._stack;
	}
	return (*this);
}

template <class T>
MutantStack<T>::~MutantStack()
{}

template <class T>
void	MutantStack<T>::pushStack(T value)
{
	this->_stack.push_back(value);
}

template <class T>
T const	&MutantStack<T>::topStack(void) const
{
	return (this->_stack.back());
}

template <class T>
size_t	MutantStack<T>::sizeStack(void)
{
	return (this->_stack.size());
}

template <class T>
bool	MutantStack<T>::emptyStack(void)
{
	return (this->_stack.empty());
}

template <class T>
void	MutantStack<T>::popStack(void)
{
	this->_stack.pop_back();
}