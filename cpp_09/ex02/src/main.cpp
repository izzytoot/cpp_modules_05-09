/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabeltootill <isabeltootill@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 12:39:21 by icunha-t          #+#    #+#             */
/*   Updated: 2025/10/19 01:00:13 by isabeltooti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

int main (int ac, char** av){
    if (ac < 2){
        std::cerr << RED << "Error. Usage: ./RPN <positive integer sequence>" << RES << std::endl;
        return 1;
    }

    PmergeMe sequence;
    sequence.fillContainers(ac, av);
    sequence.sort();
    
    return 0;
}