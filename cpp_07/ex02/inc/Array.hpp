/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 15:12:59 by icunha-t          #+#    #+#             */
/*   Updated: 2025/09/18 17:47:18 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iomanip>
#include <iostream>
#include <cstdlib>
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
class Array{
	private:
		T* _elements;
		unsigned int _size;
		
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& src);

		Array& operator= (const Array& src);
		T& operator[](unsigned int index);
		const T& operator[](unsigned int index) const;

		~Array();

		unsigned int size() const;
};

#include "../src/Array.tpp"
