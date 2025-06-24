/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfine.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 09:53:50 by athonda           #+#    #+#             */
/*   Updated: 2025/06/24 12:55:07 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>

template <typename T>
typename T::iterator	easyfind(T &input, int	num)
{
	for (typename T::iterator it = input.begin(), it != input.end(), ++it)
	{
		if (*it == num)
			return (it);
	}
	return (it);

}