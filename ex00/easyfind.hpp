/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfine.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 09:53:50 by athonda           #+#    #+#             */
/*   Updated: 2025/06/24 13:25:15 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <stdexcept>

template <typename T>
typename T::iterator	easyfind(T &input, int	num)
{

	typename T::iterator it;
	for (it = input.begin(); it != input.end(); ++it)
	{
		if (*it == num)
			return (it);
	}
	if (it == input.end())
		throw std::out_of_range("not found.");
	return (it);

}