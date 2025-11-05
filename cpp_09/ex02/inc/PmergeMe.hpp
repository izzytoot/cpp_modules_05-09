/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabeltootill <isabeltootill@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 12:39:21 by icunha-t          #+#    #+#             */
/*   Updated: 2025/11/05 19:14:21 by isabeltooti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>
#include <stack>
#include <exception>
#include <cstdlib>
#include <vector>


#define RED "\033[0;31m"
#define GRN "\033[0;32m"  
#define YEL "\033[0;33m"
#define CYA "\033[36m" 
#define BRED "\033[31;1m"
#define BGRN "\033[32;1m"
#define BYEL "\033[33;1m"
#define BCYA "\033[36;1m"
#define RES "\033[0m"

class PmergeMe{
    private:
        std::deque<int> _deq;
        std::vector<int> _vec;
        bool _debug;

        std::vector<std::vector<int> > reSizeNextRoundVec(const std::vector<std::vector<int> >& recGroups, size_t gSize);
        std::vector<int> jacobSthalSeqVec(size_t max);
        size_t binarySearchVec(std::vector<std::vector<int> >& main, std::vector<int> pendValue);

        std::vector<std::vector<int> > pairAndSortVec();
        std::vector<std::vector<int> > vecRecursiveSorting(std::vector<std::vector<int> > groups, int lvl, size_t gSize);
        std::vector<std::vector<int> > unfoldAndGroupVec(std::vector<std::vector<int > > groups, size_t gSize, int lvl, int flag);

        
        std::deque<std::deque<int> > reSizeNextRoundDeq(const std::deque<std::deque<int> >& recGroups, size_t gSize);
        std::deque<int> jacobSthalSeqDeq(size_t max);
        size_t binarySearchDeq(std::deque<std::deque<int> >& main, std::deque<int> pendValue);
        
        std::deque<std::deque<int> > pairAndSortDeq();
        std::deque<std::deque<int> > deqRecursiveSorting(std::deque<std::deque<int> > groups, int lvl, size_t gSize);
        std::deque<std::deque<int> > unfoldAndGroupDeq(std::deque<std::deque<int > > groups, size_t gSize, int lvl, int flag);

;
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& src);
        PmergeMe& operator= (const PmergeMe& src);
        ~PmergeMe();
        
        void fillContainers(int ac, char** av);
        void sort(bool debug);
};