/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:49:00 by isabeltooti       #+#    #+#             */
/*   Updated: 2025/09/17 15:17:34 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Data.hpp"
#include <stdint.h>

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