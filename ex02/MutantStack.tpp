/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 21:03:35 by athonda           #+#    #+#             */
/*   Updated: 2025/06/30 19:54:54 by athonda          ###   ########.fr       */
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
void	MutantStack<T>::push(T value)
{
	this->_stack.push_front(value);
}

template <class T>
T const	&MutantStack<T>::top(void) const
{
	return (this->_stack.front());
}