/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabeltootill <isabeltootill@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 12:39:21 by icunha-t          #+#    #+#             */
/*   Updated: 2025/10/18 11:39:41 by isabeltooti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"

int main (int ac, char** av){
    if (ac != 2){
        std::cerr << RED << "Error. Usage: ./RPN <Polish mathematical expression>" << RES << std::endl;
        return 1;
    }

    RPN expression(av[1]);
    
    try{
         expression.performOperation();
         std::cout << expression.getResult() << std::endl;
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }

    return 0;
}