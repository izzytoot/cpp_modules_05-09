/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabeltootill <isabeltootill@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 14:28:42 by isabeltooti       #+#    #+#             */
/*   Updated: 2025/09/21 17:22:58 by isabeltooti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iomanip>
#include <iostream>
#include <algorithm>
#include <stdexcept>

#define RED "\033[0;31m"
#define GRN "\033[0;32m"  
#define YEL "\033[0;33m"
#define CYA "\033[36m" 
#define BRED "\033[31;1m"
#define BGRN "\033[32;1m"
#define BYEL "\033[33;1m"
#define BCYA "\033[36;1m"
#define RES "\033[0m"

template <typename T>
void easyfind(T& container, int n){
    //typename before so the compiler knows T::const_iterator is a type, and i is a variable of that type.
    //std::find returns the first found or last if not found
   typename T::iterator i = std::find(container.begin(), container.end(), n);

    if (i == container.end())
        throw std::runtime_error(std::string(RED) + "Couldn't find \"" + std::to_string(n) + "\" in the container.\n" + RES);
    else
        std::cout << GRN << "Found \"" << n << "\" in the container." << RES << std::endl;
}

template <typename T>
void easyfind(const T& container, int n){
    //typename before so the compiler knows T::const_iterator is a type, and i is a variable of that type.
    //std::find returns the first found or last if not found
   typename T::const_iterator i = std::find(container.begin(), container.end(), n);

    if (i == container.end())
        throw std::runtime_error(std::string(RED) + "Couldn't find \"" + std::to_string(n) + "\" in the container.\n" + RES);
    else
        std::cout << GRN << "Found \"" << n << "\" in the container." << RES << std::endl;
}

