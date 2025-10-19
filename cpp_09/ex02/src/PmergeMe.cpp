/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabeltootill <isabeltootill@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 12:39:21 by icunha-t          #+#    #+#             */
/*   Updated: 2025/10/19 01:05:16 by isabeltooti      ###   ########.fr       */
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

void PmergeMe::sort(){
    std::cout << "Before for deque: ";
    for (std::deque<int>::const_iterator it = this->_deque.begin(); it != this->_deque.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
  
    std::cout << "Before for vector: ";
    for (size_t j = 0; j < this->_vector.size(); j++)
        std::cout << _vector[j] << " ";
    std::cout << std::endl; 
}