/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 08:41:35 by athonda           #+#    #+#             */
/*   Updated: 2025/06/24 13:39:04 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <vector>
#include <iostream>
#include "easyfind.hpp"

void	Banner(std::string title)
{
	std::cout << "\n--- " << title << " ---" << std::endl;
}

int	main(void)
{
	{
	Banner("simple test - there is a numer to search");
	int	arr[] = {42, 24, 57, 111, 0};
	std::vector<int> container(arr, arr + 5);

	std::cout << "container: ";
	for (std::vector<int>::iterator it = container.begin(); it != container.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	int	num = 57;
	std::cout << "find num:" << num << " by the easyfind()" << std::endl;
	std::cout << "the result: " << *(easyfind(container, num)) << std::endl;
	}
	{
	Banner("simple test - no number");
	int	arr[] = {42, 24, 57, 111, 0};
	std::vector<int> container(arr, arr + 5);

	std::cout << "container: ";
	for (std::vector<int>::iterator it = container.begin(); it != container.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	int	num = 100;
	std::cout << "find num:" << num << " by the easyfind()" << std::endl;
	try
	{
		std::cout << "the result: " << *(easyfind(container, num)) << std::endl;
	}
	catch(std::out_of_range &e)
	{
		std::cout << e.what() << std::endl;
	}
	}
	return (0);
}