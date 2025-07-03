/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 10:51:40 by athonda           #+#    #+#             */
/*   Updated: 2025/07/03 13:58:26 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <vector>
#include <iostream>
#include "Span.hpp"

void	Banner(std::string title)
{
	std::cout << "\n--- " << title << " ---" << std::endl;
}

int		randomInt(void)
{
	unsigned int	high = static_cast<unsigned int>(std::rand()) & 0x0000FFFF;
	unsigned int	low = static_cast<unsigned int>(std::rand()) & 0xFFFF;
	unsigned int	combined = (high << 16) | low;

	return (static_cast<int>(combined));
}

int	main(void)
{
	{
	Banner("simple test");
	Span<int>	container(5);

	container.addNumber(7);
	container.addNumber(42);
	container.addNumber(24);
	container.addNumber(9);
	container.addNumber(1);
	std::vector<int>::const_iterator	it;
	for (it = container.getContainer().begin(); it != container.getContainer().end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << "test of addNumber excessing the container size" << std::endl;
	try
	{
		container.addNumber(3);
	}
	catch (std::out_of_range &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << container.shortestSpan() << std::endl;
	std::cout << container.longestSpan() << std::endl;
	Banner("same test to copied container b ");
	Span<int>	b(container);
	std::vector<int>::const_iterator	itb;
	for (itb = b.getContainer().begin(); itb != b.getContainer().end(); ++itb)
	{
		std::cout << *itb << " ";
	}
	std::cout << std::endl;
	std::cout << "test of addNumber excessing the container size" << std::endl;
	try
	{
		b.addNumber(3);
	}
	catch (std::out_of_range &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << b.shortestSpan() << std::endl;
	std::cout << b.longestSpan() << std::endl;
	Banner("same test to assigned container c ");
	Span<int>	c = container;
	std::vector<int>::const_iterator	itc;
	for (itc = c.getContainer().begin(); itc != c.getContainer().end(); ++itc)
	{
		std::cout << *itc << " ";
	}
	std::cout << std::endl;
	std::cout << "test of addNumber excessing the container size" << std::endl;
	try
	{
		c.addNumber(3);
	}
	catch (std::out_of_range &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << c.shortestSpan() << std::endl;
	std::cout << c.longestSpan() << std::endl;

	Banner("add range test: insert first container into container a");
	Span<int>	a(10);
	try
	{
		a.addNumber(2147483647);
	}
	catch (std::out_of_range &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "make container a, and add number " << a.getContainer().front() << std::endl;
	std::cout << "then, try to insert original container above " << std::endl;
	try
	{
		a.addRange(container.getContainer().begin(), container.getContainer().end());
	}
	catch (std::out_of_range &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "here is the new container a" << std::endl;
	std::vector<int>::const_iterator	ita;
	for (ita = a.getContainer().begin(); ita != a.getContainer().end(); ++ita)
	{
		std::cout << *ita << " ";
	}
	std::cout << std::endl;
	std::cout << "now, try to insert original container again " << std::endl;
	try
	{
		a.addRange(container.getContainer().begin(), container.getContainer().end());
	}
	catch (std::out_of_range &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	Banner("add range test: range can be array");
	int	arr[] = {333, 444, 555};
	std::size_t size = sizeof(arr) / sizeof(arr[0]);
	std::cout << "this is array: " << std::endl;
	for (std::size_t i = 0; i < size; ++i)
	{
		std::cout << arr[i] << " " ;
	}
	std::cout << std::endl;
	std::cout << "then, try to insert array into container a " << std::endl;
	try
	{
		a.addRange(arr, arr + size);
	}
	catch (std::out_of_range &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "here is the new container a" << std::endl;
	std::vector<int>::const_iterator	itr;
	for (itr = a.getContainer().begin(); itr != a.getContainer().end(); ++itr)
	{
		std::cout << *itr << " ";
	}
	std::cout << std::endl;

	std::cout << a.shortestSpan() << std::endl;
	std::cout << a.longestSpan() << std::endl;
	}

	{
	Banner("10000 test");
	Span<int>	c(10000);

	std::srand(static_cast<unsigned int>(std::time(0)));
	std::size_t const	COUNT = 10000;

	for (std::size_t i = 0; i < COUNT; ++i)
	{
		c.addNumber(randomInt());
	}
	std::cout << c.shortestSpan() << std::endl;
	std::cout << c.longestSpan() << std::endl;
	}
	{
	Banner("empty contaner test");
	Span<int>	con(0);
	try
	{
		con.addNumber(42);
	}
	catch(std::out_of_range &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << con.shortestSpan() << std::endl;
	}
	catch (std::runtime_error &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << con.longestSpan() << std::endl;
	}
	catch (std::runtime_error &e)
	{
		std::cout << e.what() << std::endl;
	}
	}
	return (0);
}