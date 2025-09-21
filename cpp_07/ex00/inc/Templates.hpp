/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Templates.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 11:26:14 by icunha-t          #+#    #+#             */
/*   Updated: 2025/09/19 15:30:40 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 

#include <iomanip>
#include <string>
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

// we're saying this is not a normal function - it's a template. 
// In a template, the types are not yet decided - they'll only be define when being used
template <typename T> 
void swap(T& x, T& y){
	T tmp = x;
	x = y;
	y = tmp;
}

template <typename T>
const T& min(const T& x, const T& y){
	return (x < y ? x : y);
}

template <typename T>
const T& max(const T& x, const T& y){
	return (x > y ? x : y);
}