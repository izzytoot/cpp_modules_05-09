/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabeltootill <isabeltootill@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:24:02 by isabeltooti       #+#    #+#             */
/*   Updated: 2025/09/22 17:50:38 by isabeltooti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"

int main()
{
    std::cout << BCYA << "****** CREATING  CONTAINER WITH 5 SPACES ******" << RES << std::endl;   
    
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "Container contains the following numbers: " << std::endl;
    for (int i = 0; i < 5; i++)
        std::cout << BYEL << "_N[" << i << "]: " << RES << sp._N[i];
    
    std::cout << BCYA << "* TEST 1 - GET SHORTEST SPAN *" << RES << std::endl;   
    try{
        std::cout << BYEL << "Shortest span: " << RES << sp.shortestSpan() << std::endl;   
    }catch (std::exception& e){
        std::cerr << e.what();
    }

    std::cout << std::endl << BCYA << "* TEST 2 - GET LONGEST SPAN *" << RES << std::endl;   
    try{
        std::cout << BYEL << "Longest span: " << RES << sp.longestSpan() <<  std::endl;
    }catch (std::exception& e){
        std::cerr << e.what();
    }

        std::cout << std::endl << BCYA << "* TEST 3 - TRY TO ADD ANOTHER NUMBER *" << RES << std::endl;   
    try{
       sp.addNumber(15);
    }catch (std::exception& e){
        std::cerr << e.what();
    }
    return 0;
}