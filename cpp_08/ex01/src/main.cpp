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
    
    Span sp1 = Span(5);
    sp1.addNumber(6);
    sp1.addNumber(3);
    sp1.addNumber(17);
    sp1.addNumber(9);
    sp1.addNumber(11);

    std::cout << "Container 1 contains the following numbers: ";
    for (int i = 0; i < 5; i++)
        std::cout << sp1.getValue(i) << " ";
    std::cout << std::endl;

    std::cout << std::endl << BCYA << "* TEST 1 - GET SHORTEST SPAN *" << RES << std::endl;   
    try{
        std::cout << BYEL << "Shortest span: " << RES << sp1.shortestSpan() << std::endl;   
    }catch (std::exception& e){
        std::cerr << e.what();
    }

    std::cout << std::endl << BCYA << "* TEST 2 - GET LONGEST SPAN *" << RES << std::endl;   
    try{
        std::cout << BYEL << "Longest span: " << RES << sp1.longestSpan() <<  std::endl;
    }catch (std::exception& e){
        std::cerr << e.what();
    }

        std::cout << std::endl << BCYA << "* TEST 3 - TRY TO ADD ANOTHER NUMBER *" << RES << std::endl;   
    try{
       sp1.addNumber(15);
    }catch (std::exception& e){
        std::cerr << e.what();
    }

    std::cout << std::endl << BCYA << "****** CREATING  CONTAINER WITH 10 EMPTY SPACES ******" << RES << std::endl;   
    Span sp2 = Span(10);

    std::cout << "Container 2 contains the following numbers: ";
    for (unsigned int i = 0; i < sp2.getMax(); i++)
        std::cout << sp2.getValue(i) << " ";
    std::cout << std::endl;

    std::cout << std::endl << BCYA << "* TEST 1 - GET SHORTEST SPAN *" << RES << std::endl;   
    try{
        sp2.shortestSpan();
    }catch (std::exception& e){
        std::cerr << e.what();
    }
    std::cout << std::endl;

    std::cout << BCYA << "* ADDING VALUES *" << RES << std::endl;   

    for (unsigned int i = 0; i < sp2.getMax(); i++)
        sp2.addNumber(i);

    std::cout << "Container 2 now contains the following numbers: ";
    for (unsigned int i = 0; i < sp2.getMax(); i++)
        std::cout << sp2.getValue(i) << " ";
    std::cout << std::endl;

    std::cout << std::endl << BCYA << "* TEST 2 - GET LONGEST SPAN *" << RES << std::endl;   
    try{
        std::cout << BYEL << "Longest span: " << RES << sp2.longestSpan() <<  std::endl;
    }catch (std::exception& e){
        std::cerr << e.what();
    }

    std::cout << std::endl << BCYA << "* TEST 3 - GET SHORTEST SPAN *" << RES << std::endl;   
    try{
        std::cout << BYEL << "Shortest span: " << RES << sp2.shortestSpan() <<  std::endl;
    }catch (std::exception& e){
        std::cerr << e.what();
    }

    std::cout << std::endl << BCYA << "****** CREATING  CONTAINER WITH 10.000 SPACES ******" << RES << std::endl;   
    Span sp3 = Span(10000);
    for (unsigned int i = 0; i < sp3.getMax(); i++)
        sp3.addNumber(i * 2);

    std::cout << std::endl << BCYA << "* TEST 1 - GET SHORTEST SPAN *" << RES << std::endl;   
    try{
         std::cout << BYEL << "Shortest span: " << RES << sp3.shortestSpan() <<  std::endl;
    }catch (std::exception& e){
        std::cerr << e.what();
    }
    std::cout << std::endl;

    std::cout << BCYA << "* TEST 2 - GET LONGEST SPAN *" << RES << std::endl;   
    try{
        std::cout << BYEL << "Longest span: " << RES << sp3.longestSpan() <<  std::endl;
    }catch (std::exception& e){
        std::cerr << e.what();
    }

    std::cout << std::endl << BCYA << "****** CREATING  CONTAINER WITH 10 SPACES AND ADD 5 VALUES ******" << RES << std::endl;   
    Span sp4 = Span(10);
    for (int i = 0; i < 5; i++){
        sp4.addNumber(i + 1);
    }

    std::cout << "Container 4 contains the following numbers: ";
    for (unsigned int i = 0; i < 5; i++)
        std::cout << sp4.getValue(i) << " ";
    std::cout << std::endl;

    std::cout << std::endl << BCYA << "* ADD ANOTHER 5 WITH ADDMULTIPLE *" << RES << std::endl;
    std::vector<int> vec;
    for (int i = 6; i <= 10; i++)
        vec.push_back(i);
    sp4.addMultiple(vec.begin(), vec.end());

    std::cout << "Container 4 now contains the following numbers: ";
    for (unsigned int i = 0; i < sp4.getSize(); i++)
        std::cout << sp4.getValue(i) << " ";
    std::cout << std::endl;

    std::cout << std::endl << BCYA << "* TEST 1 - GET LONGEST SPAN *" << RES << std::endl;   
    try{
        std::cout << BYEL << "Longest span: " << RES << sp4.longestSpan() <<  std::endl;
    }catch (std::exception& e){
        std::cerr << e.what();
    }

    std::cout << std::endl << BCYA << "* TEST 2 - GET SHORTEST SPAN *" << RES << std::endl;   
    try{
        std::cout << BYEL << "Shortest span: " << RES << sp4.shortestSpan() <<  std::endl;
    }catch (std::exception& e){
        std::cerr << e.what();
    }

    return 0;
}