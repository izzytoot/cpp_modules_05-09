/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabeltootill <isabeltootill@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:49:00 by isabeltooti       #+#    #+#             */
/*   Updated: 2025/09/15 15:16:41 by isabeltooti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iomanip>
#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include <cmath>
#include "Data.hpp"

#define RED "\033[0;31m"
#define GRN "\033[0;32m"  
#define YEL "\033[0;33m"
#define CYA "\033[36m" 
#define BRED "\033[31;1m"
#define BGRN "\033[32;1m"
#define BYEL "\033[33;1m"
#define BCYA "\033[36;1m"
#define RES "\033[0m"

class Serializer{
    private:
        Serializer();
        Serializer(const Serializer& src);
        
        Serializer& operator= (const Serializer& src);
        
        ~Serializer();
        
    public:
        static uintptr_t serialize(Data* ptr); //takes a memory address and stores it as a number
        static Data* deserialize(uintptr_t raw); //converts uintptr_t back into a data ptr
};