/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 18:21:52 by athonda           #+#    #+#             */
/*   Updated: 2025/07/01 09:23:50 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <deque>

template <class T>
class MutantStack :
	public std::stack<T>
{
	public:
		MutantStack();
		MutantStack(MutantStack const &other);
		MutantStack	&operator=(MutantStack const &other);
		~MutantStack();

		typedef typename std::deque<T>::iterator iterator;

		typename std::deque<T>::iterator	begin();
		iterator	end();
//		void	push(T value);
//		T const	&top(void) const;
//		size_t	size(void);
//		bool	empty(void);
//		void	pop(void);
	private:
		std::deque<T> _stack;
};

# include "MutantStack.tpp"
#endif