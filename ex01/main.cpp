/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 10:51:40 by athonda           #+#    #+#             */
/*   Updated: 2025/07/01 22:11:05 by athonda          ###   ########.fr       */
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
	unsigned int	high = static_cast<unsigned int>(std::rand()) & 0xFFFF;
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
	Span<int>	b(container);
	Span<int>	c = container;
	std::cout << "test of addNumber excessing the container size" << std::endl;
	try
	{
		container.addNumber(3);
	}
	catch (std::out_of_range &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::vector<int>::const_iterator	it;
	for (it = container.getContainer().begin(); it != container.getContainer().end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << container.shortestSpan() << std::endl;
	std::cout << container.longestSpan() << std::endl;
	Banner("same test to copied b ");
	std::cout << "test of addNumber excessing the container size" << std::endl;
	try
	{
		b.addNumber(3);
	}
	catch (std::out_of_range &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::vector<int>::const_iterator	itb;
	for (itb = b.getContainer().begin(); itb != b.getContainer().end(); ++itb)
	{
		std::cout << *itb << " ";
	}
	std::cout << std::endl;
	std::cout << b.shortestSpan() << std::endl;
	std::cout << b.longestSpan() << std::endl;
	Banner("same test to assigned c ");
	std::cout << "test of addNumber excessing the container size" << std::endl;
	try
	{
		c.addNumber(3);
	}
	catch (std::out_of_range &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::vector<int>::const_iterator	itc;
	for (itc = c.getContainer().begin(); itc != c.getContainer().end(); ++itc)
	{
		std::cout << *itc << " ";
	}
	std::cout << std::endl;
	std::cout << c.shortestSpan() << std::endl;
	std::cout << c.longestSpan() << std::endl;
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