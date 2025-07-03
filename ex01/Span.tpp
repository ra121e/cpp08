/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 11:33:50 by athonda           #+#    #+#             */
/*   Updated: 2025/07/03 14:38:51 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include <iterator> //distance

template <typename T>
Span<T>::Span()
{}

template <typename T>
Span<T>::Span(unsigned int n):
	_N(n)
{}

template <typename T>
Span<T>::Span(const Span &other):
	_N(other._N),
	_container(other._container)
{}

template <typename T>
Span<T>	&Span<T>::operator=(const Span &other)
{
	if (this != &other)
	{
		this->_N = other._N;
		this->_container = other._container;
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
std::vector<T> const	&Span<T>::getContainer(void) const
{
	return (this->_container);
}

template <typename T>
void	Span<T>::addNumber(unsigned int num)
{
	if (this->_container.size() >= this->_N)
		throw std::out_of_range("cannot add beyond the container size");
	else
	{
		this->_container.push_back(num);
	}
}

template <class T>
template <typename U>
void	Span<T>::addRange(U start, U last)
{
	std::size_t	rangesize = std::distance(start, last);
	if (this->_container.size() + rangesize > this->_N)
	{
		throw std::out_of_range("cannot add beyond the container size");
	}
	else
	{
		this->_container.insert(_container.end(),start, last);
	}
}

template <typename T>
unsigned int	Span<T>::shortestSpan(void)
{
	typename std::vector<T>	sortedContainer = _container;

	if (_container.size() <= 1)
		throw std::out_of_range("initial contaier size should be greater than 1.");
	std::sort(sortedContainer.begin(), sortedContainer.end());
	typename std::vector<T>	span(sortedContainer.size());
	std::adjacent_difference(sortedContainer.begin(), sortedContainer.end(), span.begin());

	if (span.empty())
		throw std::runtime_error("Empty container. not calculate shortest span");
	span.erase(span.begin());

	typename std::vector<T>::iterator	minIt;
	minIt = std::min_element(span.begin(), span.end());
	return (*minIt);
}

template <typename T>
unsigned int	Span<T>::longestSpan(void)
{
	typename std::vector<T>::iterator	minIt;
	typename std::vector<T>::iterator	maxIt;

	if (_container.size() <= 1)
		throw std::out_of_range("initial contaier size should be greater than 1.");
	minIt = std::min_element(_container.begin(), _container.end());
	if (minIt == _container.end())
		throw std::runtime_error("contaner empty.");
	maxIt = std::max_element(_container.begin(), _container.end());
	if (maxIt == _container.end())
		throw std::runtime_error("contaner empty");
	return (*maxIt - *minIt);
}