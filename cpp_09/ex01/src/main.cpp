/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabeltootill <isabeltootill@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 12:39:21 by icunha-t          #+#    #+#             */
/*   Updated: 2025/10/16 23:03:14 by isabeltooti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"

int main (int ac, char** av){
    if (ac != 2){
        std::cerr << RED << "Error. Usage: ./RPN <Polish mathematical expression>" << RES << std::endl;
        return 1;
    }

    RPN expression;
    expression.loadStack(av[1]);
    expression.get_result();

    return 0;
}