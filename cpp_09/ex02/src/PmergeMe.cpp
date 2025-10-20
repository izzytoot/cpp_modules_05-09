/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabeltootill <isabeltootill@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 12:39:21 by icunha-t          #+#    #+#             */
/*   Updated: 2025/10/20 23:30:52 by isabeltooti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe& src): _deque(src._deque), _vector(src._vector) {}

PmergeMe& PmergeMe::operator= (const PmergeMe& src){
    if (this != &src){
        this->_deque = src._deque;
        this->_vector = src._vector;
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
                std::runtime_error(RED"Error: invalid char in argument"RES);
        }
        
        int currNb;
        if (!val.empty()){
            currNb = std::atoi(val.c_str());
            this->_vector.push_back(currNb);
            this->_deque.push_back(currNb);   
        }
        else
            std::runtime_error(RED"Error: empty argument"RES);
    }
}

std::deque<std::deque<int> > PmergeMe::dequeRecursivePairing(std::deque<std::deque<int> > groups){
    if (groups.size() < 2)
        return groups;

    std::deque<std::deque<int> > nextRound;
    
    for (size_t i = 0; i + 1 < groups.size(); i += 2){
        std::deque<int>& A = groups[i];
        std::deque<int>& B = groups[i + 1];

        if (A.back() > B.back())
            std::swap(A, B);
        
        std::deque <int> jointGroup;
        jointGroup.insert(jointGroup.end(), A.begin(), A.end());
        jointGroup.insert(jointGroup.end(), B.begin(), B.end());

        nextRound.push_back(jointGroup);
    }

    if (groups.size() % 2 != 0){
        nextRound.push_back(groups.back());
    }
    return dequeRecursivePairing(nextRound);     
}

std::deque<std::deque<int> > PmergeMe::pairAndSortDeque(){
    std::deque<std::deque<int> > groups;


    for (size_t i = 0; i + 1 < this->_deque.size(); i += 2){
        std::deque<int> pair;
        int a = this->_deque[i];
        int b = this->_deque[i + 1];

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
    
    if (this->_deque.size() % 2 != 0){
        std::deque<int> oddNb;
        oddNb.push_back(this->_deque.back());
        groups.push_back(oddNb);
    }
        
    return dequeRecursivePairing(groups);
}

// std::vector<std::vector<int> > PmergeMe::vectorRecursivePairing(std::vector<std::vector<int>> groups, int oddNb){

// }

// std::vector<std::vector<int> > PmergeMe::pairAndSortVector(){
    
// }

void PmergeMe::sort(){
    std::cout << YEL << "Before for deque: " << RES;
    for (std::deque<int>::const_iterator it = this->_deque.begin(); it != this->_deque.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
  
    std::cout << YEL << "Before for vector: " << RES;
    for (size_t j = 0; j < this->_vector.size(); j++)
        std::cout << this->_vector[j] << " ";
    std::cout << std::endl;

    clock_t start = clock();
    std::deque<std::deque<int> > dqFJPhase1 = pairAndSortDeque();
    //phase 2
    //phase 3
    clock_t end = clock();
    double _dqTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000; // Convert to microseconds
    std::cout << "Time to process a range of " << this->_deque.size() << " elements with std::deque: " << _dqTime << " us" << std::endl;
    
    // start = clock();
    // std::vector<std::vector<int>> vecFJPhase1 = pairAndSortVector();
    // //phase 2
    // //phase 3
    // end = clock();
    // double _dqTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000; // Convert to microseconds
    // std::cout << "Time to process a range of " << this->_vector.size() << " elements with std::vector: " << _dqTime << " us" << std::endl;
}