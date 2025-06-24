/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 08:41:35 by athonda           #+#    #+#             */
/*   Updated: 2025/06/24 13:19:15 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include "easyfine.hpp"

int	main(void)
{
	int	arr[] = {42, 24, 57, 111, 0};
	std::vector<int> container(arr, arr + 5);
	std::cout << "container: " << container[0] << std::endl;
	int	num = 57;
	std::cout << "find num:" << num << " by the easyfind()" << std::endl;
	std::cout << "the result: " << *(easyfind(container, num)) << std::endl;
	return (0);
}