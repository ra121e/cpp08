/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 10:51:40 by athonda           #+#    #+#             */
/*   Updated: 2025/06/27 21:29:09 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"

int	main(void)
{
	Span<int>	container(5);

	container.addNumber(7);
	container.addNumber(2);
	container.addNumber(1);
	container.addNumber(9);
	container.addNumber(42);
	container.addNumber(0);
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

	return (0);
}