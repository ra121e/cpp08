/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 18:21:52 by athonda           #+#    #+#             */
/*   Updated: 2025/07/01 18:00:18 by athonda          ###   ########.fr       */
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
		typedef typename std::deque<T>::const_iterator const_iterator;

		typename std::deque<T>::iterator	begin();
		iterator		end();
		const_iterator	begin() const;
		const_iterator	end() const;

	private:
		std::deque<T> _stack;
};

# include "MutantStack.tpp"
#endif