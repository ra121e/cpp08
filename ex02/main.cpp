/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 17:38:50 by athonda           #+#    #+#             */
/*   Updated: 2025/06/30 14:39:31 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <stack>
#include "MutantStack.hpp"

void	Banner(std::string title)
{
	std::cout << "\n--- " << title << " ---" << std::endl;
}

int	main(void)
{
	{
	Banner("simple test");
	std::stack<int>	a;
	std::cout << "stack a is empty or not: " << a.empty() << std::endl;
	std::cout << "now, push number 5 on top." << std::endl;
	a.push(5);
	std::cout << "stack a: " << a.top() << std::endl;
	std::cout << "now, push number 42 and 24 on top." << std::endl;
	a.push(42);
	a.push(24);
	std::cout << "size of a: " << a.size() << std::endl;
	std::cout << "stack a is empty or not: " << a.empty() << std::endl;
	std::cout << "stack a: " << a.top() << std::endl;
	std::cout << "now, pop on top." << std::endl;
	a.pop();
	std::cout << "stack a: " << a.top() << std::endl;

	std::stack<int>	b;
	std::cout << "now, make stack b and copy from a." << std::endl;
	b = a;
	std::cout << "stack b: " << a.top() << std::endl;
	}

	{
	Banner("MutantStack test");
	MutantStack<int>	a;
	a.pushStack(6);
	std::cout << "a: " << a.topStack() << std::endl;
	std::cout << "size: " << a.sizeStack() << std::endl;
	std::cout << "empty: " << a.emptyStack() << std::endl;
	a.pushStack(3);
	a.pushStack(42);
	std::cout << "a: " << a.topStack() << std::endl;
	a.popStack();
	std::cout << "a: " << a.topStack() << std::endl;

	Banner("iterator test");
	MutantStack<int>::Iterator it;
	it = a.begin();
	std::cout << "iterator " << *it << std::endl;
	std::cout << "iterator " << *++it << std::endl;
	}

	return (0);
}