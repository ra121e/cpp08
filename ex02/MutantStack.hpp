/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 18:21:52 by athonda           #+#    #+#             */
/*   Updated: 2025/06/30 12:38:36 by athonda          ###   ########.fr       */
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
		size_t	sizeStack(void);
		bool	emptyStack(void);
		void	popStack(void);

		class Iterator
		{
			public:
				Iterator();
				Iterator(typename std::vector<T>::iterator const &it);
				Iterator(Iterator const &other);
				Iterator	&operator=(Iterator const &other);
				~Iterator();

				T	&operator*();
				Iterator	&operator++();
//				Iterator	&operator++(int);
			private:
				typename std::vector<T>::iterator	_it;
		};

		Iterator	begin();
		Iterator	end();
	private:
		std::vector<T> _stack;
};

# include "MutantStack.tpp"
#endif