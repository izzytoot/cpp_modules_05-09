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
                std::runtime_error(RED "Error: invalid char in argument" RES);
        }
        
        int currNb;
        if (!val.empty()){
            currNb = std::atoi(val.c_str());
            this->_vector.push_back(currNb);
            this->_deque.push_back(currNb);   
        }
        else
            std::runtime_error(RED "Error: empty argument" RES);
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

    if (groups.size() % 2 != 0)
        nextRound.push_back(groups.back());

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

std::vector<std::vector<int> > PmergeMe::vectorRecursivePairing(std::vector<std::vector<int> > groups){
    if (groups.size() < 2)
        return groups;
    
    std::vector<std::vector<int> > nextRound;
    for (size_t i = 0; (i + 1) < groups.size(); i += 2){
        std::vector<int>& A = groups[i];
        std::vector<int>& B = groups[i + 1];

        if (A.back() > B.back())
            std::swap(A, B);
        
        std::vector<int> jointGroup;
        jointGroup.insert(jointGroup.end(), A.begin(), B.begin());

        nextRound.push_back(jointGroup);
    }

    if (groups.size() % 2 != 0)
        nextRound.push_back(groups.back());

    return vectorRecursivePairing(nextRound);
}

std::vector<std::vector<int> > PmergeMe::pairAndSortVector(){
    std::vector<std::vector<int> > groups;

    for (size_t i = 0; (i + 1) < this->_vector.size(); i += 2){
        std::vector<int> pair;
        int a = this->_vector[i];
        int b = this->_vector[i + 1];

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
    
    if (this->_vector.size() % 2 != 0){
        std::vector<int> oddNb;
        oddNb.push_back(this->_vector.back());
        groups.push_back(oddNb);
    }
     
    return vectorRecursivePairing(groups);
}

void PmergeMe::sort(){
    std::cout << YEL << "Before for deque: " << RES;
    for (std::deque<int>::const_iterator it = this->_deque.begin(); it != this->_deque.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
  
    std::cout << YEL << "Before for vector: " << RES;
    for (size_t j = 0; j < this->_vector.size(); j++)
        std::cout << this->_vector[j] << " ";
    std::cout << std::endl;

    try{
        clock_t start = clock();
        std::deque<std::deque<int> > dqFJPhase1 = pairAndSortDeque();
        //phase 2
        //phase 3
        clock_t end = clock();

        std::cout << std::endl;
        std::cout << YEL << "Deque phase 1: " << RES;
        for (size_t i = 0; i < dqFJPhase1.size(); i++){
            for (size_t j = 0; j < dqFJPhase1[i].size(); j++)
                std::cout << dqFJPhase1[i][j] << " ";
        }
        double _time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000; // Convert to microseconds
        std::cout << std::endl;
        std::cout << YEL << "Time to process a range of " << this->_deque.size() << " elements with" << BYEL << " std::deque: " << RES << _time << " us" << std::endl;
        std::cout << std::endl;
    } catch(std::exception& e){}

    try{
        clock_t start = clock();
        std::vector<std::vector<int> > vecFJPhase1 = pairAndSortVector();
        //phase 2
        //phase 3
        clock_t end = clock();
        
        std::cout << YEL << "Vector phase 1: " << RES;
        for (int i = 0; i < static_cast<int>(vecFJPhase1.size()); i++){
        for (int j = 0; j < static_cast<int>(vecFJPhase1.size()); j++)
            std::cout << vecFJPhase1[i][j] << " ";
        }  
        std::cout << std::endl;
        long _time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000; // Convert to microseconds
        std::cout << YEL << "Time to process a range of " << this->_vector.size() << " elements with" << BYEL << " std::vector: " << RES << _time << " us" << std::endl;
        
    } catch (std::exception& e){}
    

}