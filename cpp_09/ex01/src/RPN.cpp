/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabeltootill <isabeltootill@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 12:39:21 by icunha-t          #+#    #+#             */
/*   Updated: 2025/10/18 11:46:18 by isabeltooti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"

RPN::RPN() {}

RPN::RPN(std::string input): _input(input) {}

RPN::RPN(const RPN& src): _input(src._input), _stack(src._stack) {}

const RPN& RPN::operator= (const RPN& src) {
    if (this != &src){
        this->_input = src._input;
        this->_stack = src._stack;
    }
    return *this;
}

RPN::~RPN() {}

int RPN::getResult() {
    if (this->_stack.size() > 1)
        throw std::runtime_error(RED"Error: invalid result => more than one element left in the stack."RES);
    if (this->_stack.size() <= 0)
        throw std::runtime_error(RED"Error: invalid result => no elements in the stack."RES);

    return this->_stack.top();
}

void RPN::performOperation() {
    
    for (size_t i = 0; i < this->_input.size(); i++){
        if (this->_input[i] >= '0' && this->_input[i] <= '9'){
            if (this->_input[i + 1] && (this->_input[i + 1] >= '0' && this->_input[i + 1] <= '9'))
                throw std::runtime_error(RED"Error: bad input => number > 9."RES);   
            else {
                this->_stack.push(this->_input[i] - '0');
                continue;
            }
        }

        else if (this->_input[i] == '-' && (this->_input[i + 1] && (this->_input[i + 1] >= '0' && this->_input[i + 1] <= '9'))){
            std::cout << this->_input[i + 1] << std::endl;
            throw std::runtime_error(RED"Error: bad input => number < 0."RES);
        }  
        else if (this->_input[i] == '+' || this->_input[i] == '-' || this->_input[i] == '*' || this->_input[i] == '/'){
            int result = doTheMath(this->_input[i]);
            this->_stack.push(result);
            continue;
        }

        else if (this->_input[i] != ' ' && (this->_input[i] < '0' || this->_input[i] > '9'))
            throw std::runtime_error(RED"Error: bad input => invalid char."RES);
    }
}

int RPN::doTheMath(char op){
    
    if (this->_stack.size() < 2)
        throw std::runtime_error(RED"Error: impossible to perform operation"RES);
    
    int second = this->_stack.top();
    this->_stack.pop();
    
    int first = this->_stack.top();
    this->_stack.pop();

    int result;
    switch(op){
        case '+': 
            result = first + second;
            break;
        case '-': 
            result = first - second;
            break;
        case '*': 
            result = first * second;
            break;
        case '/': 
            if (second == 0)
                throw std::runtime_error(RED"Error: invalid operation."RES);   
            else
                result = first / second;
            break;
    }
    return result;
}
