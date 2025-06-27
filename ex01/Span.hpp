/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 12:27:57 by athonda           #+#    #+#             */
/*   Updated: 2025/06/27 19:05:08 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>

template <typename T>
class Span
{
	public:
		Span();
		Span(unsigned int n);
		Span(Span const &other);
		Span	&operator=(Span const &other);
		~Span();

		unsigned int	getSize(void) const;

		void	addNumber(unsigned int num);
//		shortestSpan();
//		longestSpan();
	private:
		unsigned int	_N;
		std::vector<T>	_container;
};