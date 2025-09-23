/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabeltootill <isabeltootill@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:05:04 by isabeltooti       #+#    #+#             */
/*   Updated: 2025/09/22 17:56:49 by isabeltooti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"

/******************************************************************************/
/*                  Constructors, Copy Constructor, Destructor                 */
/******************************************************************************/
Span::Span(): _max(0){
    //std::cout << GRN << "Default Span constructed with 0 slots." << RES << std::endl;
}

Span::Span(unsigned int n){
    for (unsigned int i = 0; i < n; i++)
        this->_N.reserve(n);
    this->_max = n;
    //std::cout << GRN << "Span with a maximum of \"" << n << "\" slots constructed." << RES << std::endl;
    return; 
}

Span::Span(const Span& src){
    this->_max = src.getMax();
    for (unsigned int i = 0; i < _max; i++)
        this->_N[i] = src._N[i];
    //std::cout << GRN << "Span was copied and constructed." << RES << std::endl;
}

Span::~Span(){
    //std::cout << RED << "Span was destroyed." << RES << std::endl;
}

/******************************************************************************/
/*                                Operators                                   */
/******************************************************************************/
Span& Span::operator= (const Span& src){
    if (this != &src){
        this->_max = src._max;
        for (unsigned int i = 0; i < _max; i++)
            this->_N[i] = src._N[i];
    }
    //std::cout << GRN << "Span was copied with operator." << RES << std::endl;
    return *this;
}

int& Span::operator[] (unsigned int n){
	if (n >= _N.size() - 1)
		std::cerr << RES << "Error! Impossible to get requested number." << RES << std::endl;
	return this->_N[n];
}
/******************************************************************************/
/*                              Member Functions                              */
/******************************************************************************/
unsigned int Span::getMax() const{
    return this->_max;
}

int Span::getValue(unsigned int n) const{
    if (_N.size() == 0)
        return 0;
    else
        return this->_N[n];
}

int Span::getSize() const{
    return this->_N.size();
}

void Span::addNumber(int n){
    if (this->_N.size() < this->_max)
        this->_N.push_back(n);
    else
        throw MaxExceeded();
}

template <typename it>
void Span::addMultiple(it begining, it end){
    unsigned int qt = end - begining;
    if ((this->_N.size() + qt) > this->_max){
        throw LackSpace();
    }
    _N.insert(_N.end(), begining, end);
}

int Span::shortestSpan(){
    if (this->_N.size() < 2)
        throw MinElements();
    std::vector<int> tmp = this->_N;
    std::sort(tmp.begin(), tmp.end());
    int min = tmp[1] - tmp[0];
    for (unsigned int i = 0; i < (tmp.size() - 1); i++){
        if ((tmp[i + 1] - tmp[i]) < min)
            min = tmp[i + 1] - tmp[i];
    }
    return min;
}

int Span::longestSpan(){
    if (this->_N.size() < 2)
        throw MinElements();
    std::vector<int> tmp = this->_N;
    std::sort(tmp.begin(), tmp.end());
    return (tmp[tmp.size() - 1] - tmp[0]);
}

const char* Span::MaxExceeded::what() const throw(){
    return "\033[0;31mError! Unable to add number: _N has reached maximum number of elements.\n\033[0m";
}

const char* Span::MinElements::what() const throw(){
    return "\033[0;31mError! Unable to calculate span: _N contains less than 2 elements.\n\033[0m";
}

const char* Span::LackSpace::what() const throw(){
    return "\033[0;31mError! Unable to add multiple numbers: _N doesn't have enough space.\n\033[0m";
}
