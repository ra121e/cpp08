/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 18:21:52 by athonda           #+#    #+#             */
/*   Updated: 2025/06/30 19:49:02 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <deque>

template <class T>
class MutantStack
{
	public:
		MutantStack();
		MutantStack(MutantStack const &other);
		MutantStack	&operator=(MutantStack const &other);
		~MutantStack();

		void	push(T value);
		T const	&top(void) const;

	private:
		std::deque<T> _stack;
};

# include "MutantStack.tpp"
#endif