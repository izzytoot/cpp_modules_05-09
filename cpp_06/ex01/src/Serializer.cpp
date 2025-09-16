/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabeltootill <isabeltootill@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:48:56 by isabeltooti       #+#    #+#             */
/*   Updated: 2025/09/16 14:51:37 by isabeltooti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Serializer.hpp"

/******************************************************************************/
/*                  Constructors, Copy Constructor, Destructor                 */
/******************************************************************************/
Serializer::Serializer(){
	std::cout << BGRN
			  << "Default Serializer was constructed."
			  << RES << std::endl;
}

Serializer::Serializer(const Serializer& src){
    *this = src;
	std::cout << BGRN 
              << "Serializer was copied and constructed" 
              << RES << std::endl;
}

Serializer::~Serializer(){
	std::cout << BRED 
              << "Serializer was destroyed" 
              << RES << std::endl;
}

/******************************************************************************/
/*                                Operators                                   */
/******************************************************************************/
Serializer& Serializer::operator= (const Serializer& src){
    (void)src;
    std::cout << BGRN
			  << "Serializer was copied with operator."
			  << RES << std::endl;
    return *this;
}

/******************************************************************************/
/*                              Member Functions                              */
/******************************************************************************/

//reinterpret_cast allows conversion between unrelated pointer and integer types in a safe way
uintptr_t   Serializer::serialize(Data* ptr){
    return reinterpret_cast<uintptr_t>(ptr);
}

Data*   Serializer::deserialize(uintptr_t raw){
    return reinterpret_cast<Data*>(raw);
}
