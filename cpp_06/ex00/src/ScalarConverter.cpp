/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 15:33:54 by isabeltooti       #+#    #+#             */
/*   Updated: 2025/09/18 11:20:24 by icunha-t         ###   ########.fr       */
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
    (void)src;
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
	else if (((literal.length() == 2) && (literal[0] == '\\')) && (literal[1] == '0' || literal[1] == 'a' || literal[1] == 'b' || literal[1] == 't' || literal[1] == 'n' || literal[1] == 'v' || literal[1] == 'f' || literal[1] == 'r'))
			return true;
    return false;
}

static bool isInt(const std::string& literal){
    char *endptr;
    long nb;

    // strtol(string to long)
    // base 10 -> will only accept decimal values
    nb = std::strtol(literal.c_str(), &endptr, 10);
    if (*endptr == '\0' && (nb >= INT_MIN && nb <= INT_MAX))
        return true;
    return false;
}

static bool isFloat(const std::string& literal){
    if (literal == "nanf" || literal == "+inff" || literal == "inff" || literal == "-inff")
        return true;
        
    char *endptr;
    std::strtof(literal.c_str(), &endptr); //get endptr
    if (*endptr == 'f' && *(endptr + 1) == '\0') //strtof parses the numerical part and sets endptr to the next char upon that part (f)
        return true;
    return false;
}

static bool isDouble(const std::string& literal){
    if (literal == "nan" || literal == "+inf" || literal == "inf" || literal == "-inf")
        return true;
    
    char *endptr;
    std::strtod(literal.c_str(), &endptr); //get endptr
    if (*endptr == '\0')
        return true;
    return false;
}

static void whiteSpaces(std::string literal){ //we don't need this as long as we use $ when calling the whitespace
	std::cout << BYEL << "char: " << RES << "Non displayable" << std::endl;
	if (literal[1] == '0'){
		std::cout << BYEL << "int: " << RES << static_cast<int>('\0') << std::endl;
		std::cout << std::fixed << std::setprecision(1);
		std::cout << BYEL << "float: " << RES << static_cast<float>('\0') << "f" << std::endl;
		std::cout << BYEL << "double: " << RES << static_cast<double>('\0') << std::endl;
	}
	else if (literal[1] == 'a'){
		std::cout << BYEL << "int: " << RES << static_cast<int>('\a') << std::endl;
		std::cout << std::fixed << std::setprecision(1);
		std::cout << BYEL << "float: " << RES << static_cast<float>('\a') << "f" << std::endl;
		std::cout << BYEL << "double: " << RES << static_cast<double>('\a') << std::endl;
	}
	else if (literal[1] == 'b'){
		std::cout << BYEL << "int: " << RES << static_cast<int>('\b') << std::endl;
		std::cout << std::fixed << std::setprecision(1);
		std::cout << BYEL << "float: " << RES << static_cast<float>('\b') << "f" << std::endl;
		std::cout << BYEL << "double: " << RES << static_cast<double>('\b') << std::endl;
	}
	else if (literal[1] == 't'){
		std::cout << BYEL << "int: " << RES << static_cast<int>('\t') << std::endl;
		std::cout << std::fixed << std::setprecision(1);
		std::cout << BYEL << "float: " << RES << static_cast<float>('\t') << "f" << std::endl;
		std::cout << BYEL << "double: " << RES << static_cast<double>('\t') << std::endl;
	}
	else if (literal[1] == 'n'){
		std::cout << BYEL << "int: " << RES << static_cast<int>('\n') << std::endl;
		std::cout << std::fixed << std::setprecision(1);
		std::cout << BYEL << "float: " << RES << static_cast<float>('\n') << "f" << std::endl;
		std::cout << BYEL << "double: " << RES << static_cast<double>('\n') << std::endl;
	}
	else if (literal[1] == 'v'){
		std::cout << BYEL << "int: " << RES << static_cast<int>('\v') << std::endl;
		std::cout << std::fixed << std::setprecision(1);
		std::cout << BYEL << "float: " << RES << static_cast<float>('\v') << "f" << std::endl;
		std::cout << BYEL << "double: " << RES << static_cast<double>('\v') << std::endl;
	}
	else if (literal[1] == 'f'){
		std::cout << BYEL << "int: " << RES << static_cast<int>('\f') << std::endl;
		std::cout << std::fixed << std::setprecision(1);
		std::cout << BYEL << "float: " << RES << static_cast<float>('\f') << "f" << std::endl;
		std::cout << BYEL << "double: " << RES << static_cast<double>('\f') << std::endl;
	}
	else if (literal[1] == 'r'){
		std::cout << BYEL << "int: " << RES << static_cast<int>('\r') << std::endl;
		std::cout << std::fixed << std::setprecision(1);
		std::cout << BYEL << "float: " << RES << static_cast<float>('\r') << "f" << std::endl;
		std::cout << BYEL << "double: " << RES << static_cast<double>('\r') << std::endl;
	}
}

static void convFromChar(std::string literal){
	if (literal.length() == 1){
		char c = literal[0];
		if(std::isprint(c))
        	std::cout << BYEL << "char: " << RES << "'" << c << "'" << std::endl;
    	else
			std::cout << BYEL << "char: " << RES << "Non displayable" << std::endl;
		
		std::cout << BYEL << "int: " << RES << static_cast<int>(c) << std::endl;
		std::cout << std::fixed << std::setprecision(1);
		std::cout << BYEL << "float: " << RES << static_cast<float>(c) << "f" << std::endl;
		std::cout << BYEL << "double: " << RES << static_cast<double>(c) << std::endl;
	}
	else if (literal.length() == 2){
		whiteSpaces(literal);
	}
}

static void convFromInt(int nb){
    if (nb >= 0 && nb <= 127){
        if (std::isprint(nb))
            std::cout << BYEL << "char: " << RES << "'" << static_cast<char>(nb) << "'" << std::endl;
        else
         std::cout << BYEL << "char: " << RES << "Non displayable" << std::endl;
    }
    else
        std::cout << BYEL << "char: " << RES << "impossible" << std::endl;
    std::cout << BYEL << "int: " << RES << nb << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << BYEL << "float: " << RES << static_cast<float>(nb) << "f" << std::endl;
    std::cout << BYEL << "double: " << RES << static_cast<double>(nb) << std::endl;
}

static void convFromFloatOrDouble(double nb){
    // check exceptions char
    if (std::isnan(nb) || std::isinf(nb))
        std::cout << BYEL << "char: " << RES << "impossible" << std::endl;
    //conv db to int + convert int to char
    else{
        int tmp = static_cast<int>(nb);
        
        if (tmp >= 0 && tmp <= 127){
            if (std::isprint(nb))
                std::cout << BYEL << "char: " << RES << "'" << static_cast<char>(nb) << "'" << std::endl;
            else
                std::cout << BYEL << "char: " << RES << "Non displayable" << std::endl;
        }
        else
            std::cout << BYEL << "char: " << RES << "impossible" << std::endl;   
    }
    
    //int - check if infinit or not normal + check max && min
    if (std::isinf(nb) || std::isnan(nb) || nb <= static_cast<double>(INT_MIN)  || nb >= static_cast<double>(INT_MAX))
        std::cout <<  BYEL << "int: " << RES << "impossible" << std::endl;
    else
        std::cout << BYEL << "int: " << RES << static_cast<int>(nb) << std::endl;
        
    std::cout << std::fixed << std::setprecision(1);
    // std::cout << BYEL << "float: " << RES << static_cast<float>(nb) << "f" << std::endl;
    
    std::cout << BYEL << "double: " << RES << nb << std::endl;
}

void ScalarConverter::convert(const std::string& literal){
    if (isChar(literal))
        convFromChar(literal);
    else if (isInt(literal)){
        int nb = std::atoi(literal.c_str());
        convFromInt(nb);
    }
    else if (isFloat(literal)){
        float nb = strtof(literal.c_str(), NULL);
        convFromFloatOrDouble(static_cast<double>(nb));
    }
    else if (isDouble(literal)){
        double nb = strtod(literal.c_str(), NULL);
        convFromFloatOrDouble(nb);
    }
    else
        std::cout << RED << "Error: Invalid input." << RES << std::endl;
}