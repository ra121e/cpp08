/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 10:51:40 by athonda           #+#    #+#             */
/*   Updated: 2025/06/27 19:46:23 by athonda          ###   ########.fr       */
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
	std::vector<int>::const_iterator	it;
	for (it = container.getContainer().begin(); it != container.getContainer().end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	return (0);
}