/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabeltootill <isabeltootill@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 12:39:21 by icunha-t          #+#    #+#             */
/*   Updated: 2025/11/02 18:12:41 by isabeltooti      ###   ########.fr       */
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

std::vector<std::vector<int> > PmergeMe::reSizeNextRound(const std::vector<std::vector<int> >& recGroups, size_t gSize)
{
    std::vector<std::vector<int> > reSizedGroups;
    //for each group within recursived group
    for (size_t i = 0; i < recGroups.size(); ++i) {
        const std::vector<int>& prevGrouping = recGroups[i];
        size_t size = prevGrouping.size();
        //if group has grouping size - divide into half and push
        if (size >= 2 * gSize) {
            reSizedGroups.push_back(std::vector<int>(prevGrouping.begin(), prevGrouping.begin() + gSize));
            reSizedGroups.push_back(std::vector<int>(prevGrouping.begin() + gSize, prevGrouping.begin() + (2 * gSize)));
            //Extra tail - shouldn't happen
            if (size > 2 * gSize) {
                reSizedGroups.push_back(std::vector<int>(prevGrouping.begin() + 2 * gSize, prevGrouping.end()));
            }
        }
        //if group has exactly half grouping size (size we're fitting into now) - push
        else if (size == gSize) {
            reSizedGroups.push_back(prevGrouping);
        }
        //if group has more than half grouping size - push half first and then remainder
        else if (size >= gSize){
                reSizedGroups.push_back(std::vector<int>(prevGrouping.begin(), prevGrouping.begin() + gSize));
                reSizedGroups.push_back(std::vector<int>(prevGrouping.begin() + gSize, prevGrouping.end()));
        }
        //if group has less than half grouping size - push it all (remainder)
        else {
              reSizedGroups.push_back(prevGrouping);
        }
    }
    return reSizedGroups;
}

std::vector<std::vector<int> > PmergeMe::vectorRecursiveSorting(std::vector<std::vector<int> > groups, int lvl, size_t gSize){
        
    std::vector<std::vector<int> > nextRound;
    lvl++;

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

    if (!(nextRound.size() < 2 || (nextRound[0].size() != nextRound[1].size()))){
        std::vector<std::vector<int> > recGroups = vectorRecursiveSorting(nextRound, lvl, (gSize * 2));
        groups = reSizeNextRound(recGroups, (gSize * 2));
    }
    
    std::vector<std::vector<int> > main;
    std::vector<std::vector<int> > pend;
    std::vector<std::vector<int> > nonPart;

    std::cout << BRED << "Reordered groups lvl " << lvl << ": ";
    for (int i = 0; i < static_cast<int>(groups.size()); i++){
        for (int j = 0; j < static_cast<int>(groups[i].size()); j++)
            std::cout << groups[i][j] << " ";
        std::cout << " . ";
    }
    std::cout << RES << std::endl;
    
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
    
    //HERE - UNDERSTAND AND CREATE 2 FUNCTS
    if (!pend.empty()){
        std::vector<int> jacobSthalSeq = createJacobSthalSeq(pend.size());
        size_t last = 0; //why??
        
        for (size_t i = 0; i < jacobSthalSeq.size(); i++){
            size_t groupStart = jacobSthalSeq[i]; //print
            if (groupStart > pend.size())
                groupStart = pend.size(); //why?
            for (size_t j = groupStart; j > last; j--){
                size_t pos = binarySearchVec(main, pend[j - 1]);
                main.insert(main.begin() + pos, pend[j - 1]);
            }       
            last = groupStart;   
        }
    }
    
    return main;
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