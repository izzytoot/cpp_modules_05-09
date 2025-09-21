/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 12:59:49 by icunha-t          #+#    #+#             */
/*   Updated: 2025/09/18 15:13:46 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iomanip>
#include <iostream>

#define RED "\033[0;31m"
#define GRN "\033[0;32m"  
#define YEL "\033[0;33m"
#define CYA "\033[36m" 
#define BRED "\033[31;1m"
#define BGRN "\033[32;1m"
#define BYEL "\033[33;1m"
#define BCYA "\033[36;1m"
#define RES "\033[0m"

void increment(int& x){
	x++;
}

void printChar(const char& c){
	std::cout << c << " ";
}

template <typename T>
void printAnyType(const T& element){
	std::cout << element << " ";
}

template <typename T, typename F>
void iter(T* array, std::size_t len, F f){
	for (int i = 0; static_cast<size_t>(i) < len; i++)
		f(array[i]);
}
