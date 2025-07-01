/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 21:03:35 by athonda           #+#    #+#             */
/*   Updated: 2025/07/01 19:53:53 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>

template <class T>
MutantStack<T>::MutantStack() :
	std::stack<T>::stack()
{}

template <class T>
MutantStack<T>::MutantStack(MutantStack const &other) :
	std::stack<T>::stack(other)
{}

template <class T>
MutantStack<T>	&MutantStack<T>::operator=(MutantStack const &other)
{
	if (this != &other)
	{
		this->c = other.c;
	}
	return (*this);
}

template <class T>
MutantStack<T>::~MutantStack()
{}

template <class T>
typename std::deque<T>::iterator	MutantStack<T>::begin()
{
	return (this->c.begin());
}

template <class T>
typename MutantStack<T>::iterator	MutantStack<T>::end()
{
	return (this->c.end());
}

template <class T>
typename MutantStack<T>::const_iterator	MutantStack<T>::begin() const
{
	return (this->c.begin());
}

template <class T>
typename MutantStack<T>::const_iterator	MutantStack<T>::end() const
{
	return (this->c.end());
}