/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabeltootill <isabeltootill@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 12:39:21 by icunha-t          #+#    #+#             */
/*   Updated: 2025/11/01 14:11:57 by isabeltooti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe& src): _dequeBefore(src._dequeBefore), _vectorBefore(src._vectorBefore),_dequeAfter(src._dequeAfter), _vectorAfter(src._vectorAfter) {}

PmergeMe& PmergeMe::operator= (const PmergeMe& src){
    if (this != &src){
        this->_dequeBefore = src._dequeBefore;
        this->_vectorBefore = src._vectorBefore;
        this->_dequeAfter = src._dequeAfter;
        this->_vectorAfter = src._vectorAfter;
    }
    return *this;
}

PmergeMe::~PmergeMe(){}

void PmergeMe::fillContainers(int ac, char** av){
    for (int i = 1; i < ac; i++){
        std::string currArg = av[i];
        std::string val;
        for (size_t j = 0; j < currArg.size(); j++){
            if (currArg[j] >= '0' && currArg[j] <= '9'){
                val += currArg[j];
            }
            else if (currArg[j] != ' ')
                throw std::runtime_error(RED "Error: invalid char in argument" RES);
        }
        int currNb;
        if (!val.empty()){
            currNb = std::atoi(val.c_str());
            if (currNb < 0 || currNb > 1000)
                throw std::runtime_error(RED "Error: invalid input value" RES);
            this->_vectorBefore.push_back(currNb);
            this->_dequeBefore.push_back(currNb);   
        }
        else
            throw std::runtime_error(RED "Error: empty argument" RES);
    }
}

std::vector<std::vector<int> > PmergeMe::vectorRecursiveSorting(std::vector<std::vector<int> > groups, int lvl, size_t gSize){
    if (groups.size() < 2 || (groups[0].size() != groups[1].size()))
        return groups;
    
    lvl++;
    std::vector<std::vector<int> > nextRound;

    for (size_t i = 0; (i + 1) < groups.size(); i += 2){
        std::vector<int> A = groups[i];
        std::vector<int> B = groups[i + 1];

        if (A.back() > B.back() && (A.size() == B.size()))
            std::swap(A, B);

        std::vector<int> jointGroup;
        jointGroup.insert(jointGroup.end(), A.begin(), A.end());
        jointGroup.insert(jointGroup.end(), B.begin(), B.end());
        nextRound.push_back(jointGroup);
    }

    if (groups.size() % 2 != 0)
        nextRound.push_back(groups.back());

    std::cout << BGRN << "Grouping level " << lvl << ": " <<RES;
    for (int i = 0; i < static_cast<int>(groups.size()); i++){
        for (int j = 0; j < static_cast<int>(groups[i].size()); j++)
            std::cout << groups[i][j] << " ";
        std::cout << " . ";
    }
    std::cout << std::endl;

    nextRound = vectorRecursiveSorting(nextRound, lvl, (gSize * 2));

    //HERE
    
    std::vector<std::vector<int> > main;
    std::vector<std::vector<int> > pend;
    std::vector<std::vector<int> > nonPart;

    for (int i = 0; i < static_cast<int>(groups.size()); i++){
        if (groups[i].size() == (gSize * 2)){
            if ((i == 0) || ((i % 2) != 0))
                main.push_back(groups[i]);
            else
                pend.push_back(groups[i]);
        }
        else
            nonPart.push_back(groups[i]);
    }

    std::cout << BGRN << "Main lvl " << lvl << ": " <<RES;
    for (int i = 0; i < static_cast<int>(main.size()); i++){
        for (int j = 0; j < static_cast<int>(main[i].size()); j++)
            std::cout << main[i][j] << " ";
        std::cout << " . ";
    }
    std::cout << std::endl;

    std::cout << BGRN << "Pend lvl " << lvl << ": " <<RES;
    for (int i = 0; i < static_cast<int>(pend.size()); i++){
        for (int j = 0; j < static_cast<int>(pend[i].size()); j++)
            std::cout << pend[i][j] << " ";
        std::cout << " . ";
    }
    std::cout << std::endl;

    std::cout << BGRN << "NonPart lvl " << lvl << ": " <<RES;
    for (int i = 0; i < static_cast<int>(nonPart.size()); i++){
        for (int j = 0; j < static_cast<int>(nonPart[i].size()); j++)
            std::cout << nonPart[i][j] << " ";
        std::cout << " . ";
    }
    std::cout << std::endl;
    
    return groups;
}

std::vector<std::vector<int> > PmergeMe::pairAndSortVector(){
    std::vector<std::vector<int> > groups;

    for (size_t i = 0; (i + 1) < this->_vectorBefore.size(); i += 2){
        std::vector<int> pair;
        int a = this->_vectorBefore[i];
        int b = this->_vectorBefore[i + 1];

        if (a < b){
            pair.push_back(a);
            pair.push_back(b);
        }
        else{
            pair.push_back(b);
            pair.push_back(a);
        }
        groups.push_back(pair);
    }
    
    if (this->_vectorBefore.size() % 2 != 0){
        std::vector<int> oddNb;
        oddNb.push_back(this->_vectorBefore.back());
        groups.push_back(oddNb);
    }
    
    std::cout << BGRN << "Grouping level 1: " << RES;
    for (int i = 0; i < static_cast<int>(groups.size()); i++){
        for (int j = 0; j < static_cast<int>(groups[i].size()); j++)
            std::cout << groups[i][j] << " ";
    }
    std::cout << std::endl;

    std::vector<std::vector<int> > finalVec = vectorRecursiveSorting(groups, 1, 1);

    return (finalVec);
}

void PmergeMe::sort(){  
    std::cout << YEL << "Before for vector: " << RES;
    for (size_t j = 0; j < this->_vectorBefore.size(); j++)
        std::cout << this->_vectorBefore[j] << " ";
    std::cout << std::endl;

    try{
        clock_t start = clock();
        std::vector<std::vector<int> > vecFJPhase1 = pairAndSortVector();
        //phase 2
        //phase 3
        clock_t end = clock();
        
        std::cout << YEL << "Vector phase 1: " << RES;
        for (int i = 0; i < static_cast<int>(vecFJPhase1.size()); i++){
            for (int j = 0; j < static_cast<int>(vecFJPhase1[i].size()); j++)
            std::cout << vecFJPhase1[i][j] << " ";
        }  
        std::cout << std::endl;
        long _time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000; // Convert to microseconds
        std::cout << YEL << "Time to process a range of " << this->_vectorBefore.size() << " elements with" << BYEL << " std::vector: " << RES << _time << " us" << std::endl;
        
    } catch (std::exception& e){}
    
}