/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabeltootill <isabeltootill@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 15:16:14 by isabeltooti       #+#    #+#             */
/*   Updated: 2025/09/12 16:41:04 by isabeltooti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

int main(int ac, char **av){
    if (ac != 2){
        std::cout << RED << "Error! Correct usage: ./convert <input>" << RES << std::endl;
        return 1;
    }
    
    ScalarConverter::convert(av[1]);
    
    return 0;
}