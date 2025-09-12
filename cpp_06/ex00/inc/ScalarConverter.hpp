/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabeltootill <isabeltootill@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 14:57:36 by isabeltooti       #+#    #+#             */
/*   Updated: 2025/09/12 15:51:30 by isabeltooti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iomanip>
#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include <cmath>

#define RED "\033[0;31m"
#define GRN "\033[0;32m"  
#define YEL "\033[0;33m"
#define CYA "\033[36m" 
#define BRED "\033[31;1m"
#define BGRN "\033[32;1m"
#define BYEL "\033[33;1m"
#define BCYA "\033[36;1m"
#define RES "\033[0m"

class ScalarConverter{
    private: //so ScalarConverter can't be instantiated
        ScalarConverter();
        ScalarConverter(const ScalarConverter& src);
        ScalarConverter& operator= (const ScalarConverter& src);
        ~ScalarConverter();
        
    public:
        static void convert(const std::string& literal);
};