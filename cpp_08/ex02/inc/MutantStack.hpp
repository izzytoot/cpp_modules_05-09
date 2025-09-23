/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:41:24 by icunha-t          #+#    #+#             */
/*   Updated: 2025/09/23 15:28:46 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iomanip>
#include <iostream>
#include <stack>
#include <deque>

#define RED "\033[0;31m"
#define GRN "\033[0;32m"  
#define YEL "\033[0;33m"
#define CYA "\033[36m" 
#define BRED "\033[31;1m"
#define BGRN "\033[32;1m"
#define BYEL "\033[33;1m"
#define BCYA "\033[36;1m"
#define RES "\033[0m"

template <typename T, typename C = std::deque<T> >
class MutantStack: public std::stack<T, C>{
    public:
        MutantStack();
        MutantStack(const MutantStack& src);

        MutantStack& operator= (const MutantStack& src);

        ~MutantStack();

        //define iterators (existant in deque)
        typedef typename C::iterator iterator;
        typedef typename C::const_iterator const_iterator;
        typedef typename C::reverse_iterator reverse_iterator;
        typedef typename C::const_reverse_iterator const_reverse_iterator;  

        //declare iterating funcions
        //begin
        iterator begin();
        const_iterator begin() const;
        //end
        iterator end();
        const_iterator end() const;
        //reverse begin
        reverse_iterator rbegin();
        const_reverse_iterator rbegin() const;
        //reverse end
        reverse_iterator rend();
        const_reverse_iterator rend() const; 
};

#include "../src/MutantStack.tpp"