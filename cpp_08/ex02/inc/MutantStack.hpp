/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:41:24 by icunha-t          #+#    #+#             */
/*   Updated: 2025/09/23 14:51:39 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iomanip>
#include <iostream>
#include <stack>

#define RED "\033[0;31m"
#define GRN "\033[0;32m"  
#define YEL "\033[0;33m"
#define CYA "\033[36m" 
#define BRED "\033[31;1m"
#define BGRN "\033[32;1m"
#define BYEL "\033[33;1m"
#define BCYA "\033[36;1m"
#define RES "\033[0m"

template <typename T, typename C = std::deque<T>>
class MutantStack: public std::stack<T, C>{
    public:
        typedef typename C::iterator it;
        typedef typename C::const_iterator const_it;
        
        MutantStack();
        MutantStack(const MutantStack& src);

        MutantStack& operator= (const MutantStack& src);

        ~MutantStack();

        void iterators();   
};

#include "../src/MutantStack.tpp"


//push - add new element to the top
//top - access the top element
//pop - remove last added element
//size - get size
//empty - check if empty (1 for true)