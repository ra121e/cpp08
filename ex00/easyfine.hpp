/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfine.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 09:53:50 by athonda           #+#    #+#             */
/*   Updated: 2025/06/24 10:05:12 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>

template <typename T>
std::vector::iterator	easyfind(std::vector<T> input, int	num)
{
	for (std::vector::iterator it = input.begin(), it != input.end(), ++it)
	{
		if (*it == num)
			return (it);
	}
	return (it);

}