/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabeltootill <isabeltootill@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 12:39:21 by icunha-t          #+#    #+#             */
/*   Updated: 2025/11/03 22:47:46 by isabeltooti      ###   ########.fr       */
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
        std::deque<int> _deqBefore;
        std::vector<int> _vecBefore;
        std::deque<int> _deqAfter;
        std::vector<int> _vecAfter;

        std::vector<std::vector<int> > pairAndSortVec();
        std::vector<std::vector<int> > vecRecursiveSorting(std::vector<std::vector<int> > groups, int lvl, size_t gSize);
        std::vector<std::vector<int> > reSizeNextRound(const std::vector<std::vector<int> >& recGroups, size_t gSize);
        std::vector<int> createJacobSthalSeq(size_t size);
;
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& src);
        PmergeMe& operator= (const PmergeMe& src);
        ~PmergeMe();
        
        void fillContainers(int ac, char** av);
        void sort();
};