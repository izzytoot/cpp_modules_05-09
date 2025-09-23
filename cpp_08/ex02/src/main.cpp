/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:41:57 by icunha-t          #+#    #+#             */
/*   Updated: 2025/09/23 17:49:01 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/MutantStack.hpp"
#include <list>

int main()
{
    std::cout << std::endl << BCYA << "********* CREATE MUTANTSTACK WITH 5 INTS *********" << RES << std::endl;
    
    MutantStack<int> mstack;
    std::cout << "mstack is: ";
    for (int i = 0; i < 5; i++){
        mstack.push((i + 1) * 10);
        std::cout << (i + 1) * 10 << " ";
    }    
    std::cout << std::endl;
    
    std::cout << std::endl << BCYA << "********* TESTING MEMEBER FUNCTIONS OF STD::STACK *********" << RES << std::endl;
    std::cout << BYEL << "top(): " << RES << mstack.top() << std::endl; 
    std::cout << BYEL << "empty(): " << RES << mstack.empty() << std::endl;
    std::cout << BYEL << "size(): " << RES << mstack.size() << std::endl;
    std::cout << BYEL << "pop(): " << RES;
    mstack.pop();
    std::cout << "after pop() top() is " << mstack.top() << " and size() is " << mstack.size() << std::endl;
    std::cout << BYEL << "push(): " << RES;
    mstack.push(50);
    std::cout << "after push(50) top() is " << mstack.top() << std::endl;

    std::cout << std::endl << BCYA << "********* TESTING ITERATORS *********" << RES << std::endl;
    std::cout << std::endl << BCYA << "* CREATING NON CONST ITERATORS *" << RES << std::endl;

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();
    std::cout << BYEL << "it - begin(): " << RES << *it << std::endl;
    std::cout << BYEL << "ite - end(): " << RES << "can't dereference ite";
    ite--;
    std::cout << ", but ite-- is " << *ite << std::endl;
    ite++;
    std::cout << BYEL << "rit - rbegin(): " << RES << *rit << std::endl;
    std::cout << BYEL << "rite - rend(): " << RES << "can't dereference rite";
    rite--;
    std::cout << ", but rite-- is " << *rite << std::endl;
    rite++;

    std::cout << std::endl << BCYA << "* USING ITERATORS TO ITERATE*" << RES << std::endl;
    std::cout << BYEL << "it to ite: " << RES;
    while (it != ite)
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;

    std::cout << BYEL << "rit to rite: " << RES;
    while (rit != rite)
    {
        std::cout << *rit << " ";
        ++rit;
    }
    std::cout << std::endl;

    std::cout << std::endl << BCYA << "* CREATING CONST ITERATORS *" << RES << std::endl;
    MutantStack<int>::const_iterator cit = mstack.begin();
    MutantStack<int>::const_iterator cite = mstack.end();
    std::cout << BYEL << "cit - begin(): " << RES << *cit << std::endl;
    std::cout << BYEL << "cite - end(): " << RES << "can't dereference cite" << ", but cite-- is ";
    cite--;
    std::cout << *cite << std::endl;
    cite++;
    
    std::cout << BYEL << "cit to cite: " << RES;
    while (cit != cite)
    {
        std::cout << *cit << " ";
        ++cit;
    }
    std::cout << std::endl;

    std::cout << std::endl << BCYA << "********* COMPARING A MUTANTSTACK WITH A LIST *********" << RES << std::endl;
    MutantStack<std::string> stack;
    stack.push("hello");
    stack.push("goodbye");
    stack.push("hey");
    
    std::list<std::string> lst;
    lst.push_back("hello");
    lst.push_back("goodbye");
    lst.push_back("hey");

    MutantStack<std::string>::iterator new_it = stack.begin();
    MutantStack<std::string>::iterator new_ite = stack.end();
    
    std::cout << BYEL << "stack is: " << RES;
    while(new_it != new_ite){
        std::cout << *new_it << " ";
        new_it++;
    }
    std::cout << std::endl;
    
    std::cout << BYEL << "list is: " << RES;
    for(std::list<std::string>::iterator lit = lst.begin(); lit != lst.end(); lit++){
        std::cout << *lit << " ";
    }
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << BYEL << "top of stack is: " << RES << stack.top() << std::endl;
    std::cout << BYEL << "top(back) of list is: " << RES << lst.back() << std::endl;
    
    std::cout << std::endl;
    stack.pop();
    lst.pop_back();
    std::cout << BYEL << "after pop, top of stack is: " << RES << stack.top() << std::endl;
    std::cout << BYEL << "after pop(pop_back), top(front) of list is: " << RES << lst.back() << std::endl;
    
    return 0;
}