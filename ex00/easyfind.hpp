/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 09:53:50 by athonda           #+#    #+#             */
/*   Updated: 2025/06/25 12:25:07 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator	easyfind(T &input, int	num)
{
	typename T::iterator it;
	it = find(input.begin(), input.end(), num);
	if (it == input.end())
		throw std::out_of_range("not found.");
	return (it);

}