/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabeltootill <isabeltootill@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 15:33:54 by isabeltooti       #+#    #+#             */
/*   Updated: 2025/09/12 16:49:00 by isabeltooti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"


/******************************************************************************/
/*                  Constructors, Copy Constructor, Destructor                 */
/******************************************************************************/
ScalarConverter::ScalarConverter(){
	std::cout << BGRN
			  << "Default ScalarConverter was constructed."
			  << RES << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& src){
    *this = src;
	std::cout << BGRN 
              << "ScalarConverter was copied and constructed" 
              << RES << std::endl;
}

ScalarConverter::~ScalarConverter(){
	std::cout << BRED 
              << "ScalarConverter was destroyed" 
              << RES << std::endl;
}

/******************************************************************************/
/*                                Operators                                   */
/******************************************************************************/
ScalarConverter& ScalarConverter::operator= (const ScalarConverter& src){
    if (this != &src)
        *this = src;
    std::cout << BGRN
			  << "ScalarConverter was copied with operator."
			  << RES << std::endl;
    return *this;
}

/******************************************************************************/
/*                              Member Functions                              */
/******************************************************************************/

static bool isChar(const std::string& literal){
    if ((literal.length() == 1) && !std::isdigit(literal[0]))
        return true;
    return false;
}

static bool isInt(const std::string& literal){
    for (int i = 0; i < literal.length(); i++){
        if (!std::isdigit(literal[i])){
                return false;
        }   
    }
    if (std::atoi(literal.c_str()))
        return true;
    return false;
}
//OR
static bool isInt(const std::string& literal){
    char *end;
    long nb;

    nb = std::strtol(literal.c_str(), &end, 10); //// base 10 -> will only accept decimal notation
    if (*end == '\0' && (nb >= INT_MIN && nb <= INT_MAX))
        return true;
    return false;
}


// static bool isFloat(const std::string& literal){
    
// }

// static bool isDouble(const std::string& literal){
    
// }

static void convFromChar(char c){
    if(std::isprint(c))
        std::cout << BYEL << "char: " << RES << "'" << c << "'" << std::endl;
    else
        std::cout << BYEL << "char: " << RES << "Non displayable" << std::endl;
    std::cout << BYEL << "int: " << RES << static_cast<int>(c) << std::endl;
    std::cout << BYEL << "float: " << RES << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << BYEL << "double: " << RES << static_cast<double>(c) << ".0" << std::endl;
}

// static void convFromInt(int nb){
    
// }

// static void convFromFloat(float fl){
    
// }

// static void convFromDouble(double db){
    
// }

void ScalarConverter::convert(const std::string& literal){
    if (isChar(literal))
        convFromChar(literal[0]);
    else if (isInt(literal)){
    //     int nb = std::atoi(literal.c_str());
    //     convFromInt(nb);
    // }
    // else if (isFloat(literal)){

    // }
    // else if (isDouble(literal)){
        
    // }
    else
        std::cout << RED << "Error: Invalid input." << RES << std::endl;
    
}