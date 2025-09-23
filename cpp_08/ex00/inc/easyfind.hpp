/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 14:28:42 by isabeltooti       #+#    #+#             */
/*   Updated: 2025/09/23 19:05:30 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iomanip>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <sstream>

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
    //typename before so the compiler knows T::iterator is a type, and i is a variable of that type.
    //std::find returns the first found or last if not found
   typename T::iterator it = std::find(container.begin(), container.end(), n);

    if (it == container.end()){
        std::ostringstream os;
        os << RED << "Couldn't find \"" << n << "\" in the container.\n" << RES;
        throw std::runtime_error(os.str());
    }
    else
        std::cout << GRN << "Found \"" << n << "\" in the container." << RES << std::endl;
}

template <typename T>
void easyfind(const T& container, int n){
   typename T::const_iterator it = std::find(container.begin(), container.end(), n);

    if (it == container.end()){
        std::ostringstream os;
        os << RED << "Couldn't find \"" << n << "\" in the container.\n" << RES;
        throw std::runtime_error(os.str());
    }
    else
        std::cout << GRN << "Found \"" << n << "\" in the container." << RES << std::endl;
}

