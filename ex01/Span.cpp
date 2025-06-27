/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 11:33:50 by athonda           #+#    #+#             */
/*   Updated: 2025/06/27 19:06:24 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdexcept>
#include "Span.hpp"

template <typename T>
Span<T>::Span()
{}

template <typename T>
Span<T>::Span(unsigned int n):
	_N(n)
{}

template <typename T>
Span<T>::Span(const Span &other):
	_N(other._N)
{

}

template <typename T>
Span<T>	&Span<T>::operator=(const Span &other)
{
	if (this != &other)
	{
		this->_N = other._N;
	}
	return (*this);
}

template <typename T>
Span<T>::~Span()
{}

template <typename T>
unsigned int	Span<T>::getSize(void) const
{
	return (this->_N);
}

template <typename T>
void	Span<T>::addNumber(unsigned int num)
{
	if (num > 9)
		return ;
	if (this->_container.size() >= this->_N)
		throw std::out_of_range("cannot add beyond the container size");
	else
	{
		this->_container.push_back(num);
	}
}