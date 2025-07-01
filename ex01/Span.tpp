/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 11:33:50 by athonda           #+#    #+#             */
/*   Updated: 2025/07/01 22:04:56 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>
#include <stdexcept>

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

template <typename T>
unsigned int	Span<T>::shortestSpan(void)
{
	typename std::vector<T>	sortedContainer = _container;
	std::cout << "original: ";
	for (typename std::vector<T>::iterator it = sortedContainer.begin(); it != sortedContainer.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	std::sort(sortedContainer.begin(), sortedContainer.end());
	std::cout << "sorted: ";
	for (typename std::vector<T>::iterator it = sortedContainer.begin(); it != sortedContainer.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << "container size: " << sortedContainer.size() << std::endl;
	typename std::vector<T>	span(sortedContainer.size());
	std::adjacent_difference(sortedContainer.begin(), sortedContainer.end(), span.begin());

	std::cout << "difference: ";
	for (typename std::vector<T>::iterator it = span.begin(); it != span.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	if (span.empty())
		throw std::runtime_error("Empty container. not calculate shortest span");
	span.erase(span.begin());

	std::cout << "erase: ";
	for (typename std::vector<T>::iterator it = span.begin(); it != span.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	typename std::vector<T>::iterator	minIt;
	minIt = std::min_element(span.begin(), span.end());
	return (*minIt);
}

template <typename T>
unsigned int	Span<T>::longestSpan(void)
{
	typename std::vector<T>::iterator	minIt;
	typename std::vector<T>::iterator	maxIt;

	minIt = std::min_element(_container.begin(), _container.end());
	if (minIt == _container.end())
		throw std::runtime_error("contaner empty.");
	maxIt = std::max_element(_container.begin(), _container.end());
	if (maxIt == _container.end())
		throw std::runtime_error("contaner empty");
	return (*maxIt - *minIt);
}