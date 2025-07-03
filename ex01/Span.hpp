/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 12:27:57 by athonda           #+#    #+#             */
/*   Updated: 2025/07/03 13:38:48 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

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
		std::vector<T> const	&getContainer(void) const;

		void	addNumber(unsigned int num);

		template <typename U>
		void	addRange(U, U);
		unsigned int	shortestSpan(void);
		unsigned int	longestSpan(void);
	private:
		unsigned int	_N;
		std::vector<T>	_container;
};

# include "Span.tpp"
#endif
