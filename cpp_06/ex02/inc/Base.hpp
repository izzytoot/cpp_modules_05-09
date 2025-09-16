/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabeltootill <isabeltootill@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 11:32:13 by isabeltooti       #+#    #+#             */
/*   Updated: 2025/09/16 12:28:03 by isabeltooti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iomanip>
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>

#define RED "\033[0;31m"
#define GRN "\033[0;32m"  
#define YEL "\033[0;33m"
#define CYA "\033[36m" 
#define BRED "\033[31;1m"
#define BGRN "\033[32;1m"
#define BYEL "\033[33;1m"
#define BCYA "\033[36;1m"
#define RES "\033[0m"


class Base{
    public:
        virtual ~Base();
};

Base* generate();
void identify(Base* p);
void identify(Base& p);