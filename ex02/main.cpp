/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 17:38:50 by athonda           #+#    #+#             */
/*   Updated: 2025/07/01 09:26:21 by athonda          ###   ########.fr       */
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
	a.push(6);
	std::cout << "push 6. a is " << a.top() << std::endl;
	a.push(9);
	std::cout << "push 9. a is " << a.top() << std::endl;
	a.push(42);
	std::cout << "push 42. a is " << a.top() << std::endl;
	std::cout << "size: " << a.size() << std::endl;
	std::cout << "empty: " << a.empty() << std::endl;
	a.push(3);
	std::cout << "push 3. a is " << a.top() << std::endl;
	a.push(24);
	std::cout << "push 24. a is " << a.top() << std::endl;
	a.pop();
	std::cout << "pop the top. a: " << a.top() << std::endl;
	}
	{
	Banner("mandatory test");
	MutantStack<int>	mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	}
	return (0);
}