/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 18:21:52 by athonda           #+#    #+#             */
/*   Updated: 2025/06/28 22:47:54 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <vector>

template <class T>
class MutantStack
{
	public:
		MutantStack();
		MutantStack(MutantStack const &other);
		MutantStack	&operator=(MutantStack const &other);
		~MutantStack();

		void	pushStack(T value);
		T const	&topStack(void) const;

	private:
		std::vector<T> _stack;
};

# include "MutantStack.tpp"
#endif