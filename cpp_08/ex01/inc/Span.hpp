/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:55:47 by isabeltooti       #+#    #+#             */
/*   Updated: 2025/09/23 19:18:52 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iomanip>
#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>

#define RED "\033[0;31m"
#define GRN "\033[0;32m"  
#define YEL "\033[0;33m"
#define CYA "\033[36m" 
#define BRED "\033[31;1m"
#define BGRN "\033[32;1m"
#define BYEL "\033[33;1m"
#define BCYA "\033[36;1m"
#define RES "\033[0m"

class Span{
    private:
        std::vector<int> _N;
        unsigned int _max;

    public:
        Span();
        Span(unsigned int n);
        Span(const Span& src);

        Span& operator= (const Span& src);
        
        ~Span();
        
        unsigned int getMax() const;
        int getValue(unsigned int n) const;
        unsigned int getSize() const;
        
        void addNumber(int n);
        int shortestSpan();
        int longestSpan();
        
        template<typename it>
        void addMultiple(it start, it end);
        
        class MaxExceeded : public std::exception{
            virtual const char* what() const throw();
        };

        class MinElements : public std::exception{
            virtual const char* what() const throw();
        };

        class LackSpace : public std::exception{
            virtual const char* what() const throw();
        };
};

#include "../src/Span.tpp"