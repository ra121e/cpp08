/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 21:03:35 by athonda           #+#    #+#             */
/*   Updated: 2025/07/01 18:05:24 by athonda          ###   ########.fr       */
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
typename std::deque<T>::iterator	MutantStack<T>::begin()
{
	return (_stack.begin());
}

template <class T>
typename MutantStack<T>::iterator	MutantStack<T>::end()
{
	return (_stack.end());
}

template <class T>
typename MutantStack<T>::const_iterator	MutantStack<T>::begin() const
{
	return (_stack.begin());
}

template <class T>
typename MutantStack<T>::const_iterator	MutantStack<T>::end() const
{
	return (_stack.end());
}