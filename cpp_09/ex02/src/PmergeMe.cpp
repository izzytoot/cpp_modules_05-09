/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabeltootill <isabeltootill@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 12:39:21 by icunha-t          #+#    #+#             */
/*   Updated: 2025/10/19 22:30:59 by isabeltooti      ###   ########.fr       */
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

std::deque<std::deque<int>> PmergeMe::pairAndSortDeque(int level, size_t size){
    std::deque<std::deque<int>> pairs;


    for (size_t i = 0; i + level < size; i += (2 * level)){
        int a = this->_deque[i];
        int b = this->_deque[i + 1];

        if (a > b){
            pairs.push_back(std::deque<int>(2 * level, 0));
            pairs.back()[0] = a;
            pairs.back()[1] = b;
        }
        else{
            pairs.push_back(std::deque<int>(2 * level, 0));
            pairs.back()[0] = b;
            pairs.back()[1] = a;
        }
    }

    pairs = pairAndSortDeque(2 * level, size);
    
    int oddNb = -1;
    if (size % 2 != 0)
        oddNb = this->_deque.back();
    
    
    
}

std::vector<std::vector<int>> PmergeMe::pairAndSortVector(int level, size_t size){
    
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

    size_t size = this->_deque.size();

    clock_t start = clock();
    if (size <= 2) // compare 2 if 2
        std::deque<std::deque<int>> dqFJPhase1 = pairAndSortDeque(1, size);
    //phase 2
    //phase 3
    clock_t end = clock();
    double _dqTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000; // Convert to microseconds
    std::cout << "Time to process a range of " << this->_deque.size() << " elements with std::deque: " << _dqTime << " us" << std::endl;
    
    start = clock();
    if (size <= 2) // compare 2 if 2
        std::vector<std::vector<int>> vecFJPhase1 = pairAndSortVector(1, size);
    //phase 2
    //phase 3
    end = clock();
    double _dqTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000; // Convert to microseconds
    std::cout << "Time to process a range of " << this->_vector.size() << " elements with std::vector: " << _dqTime << " us" << std::endl;
}