/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabeltootill <isabeltootill@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 14:28:57 by isabeltooti       #+#    #+#             */
/*   Updated: 2025/09/21 17:32:19 by isabeltooti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/easyfind.hpp"
#include <vector>
#include <list>

int main(){
    std::cout << BYEL << "*** USING A NON CONST VECTOR ***" << RES << std::endl;
    std::vector<int> vec;
    for (int i = 0; i < 10; i++)
        vec.push_back(i);

    std::cout << BCYA << "*** TEST 1 - FINDABLE VALUE ***" << RES << std::endl;
    try{
         ::easyfind(vec, 7);
    }catch (std::exception& e){
        std::cerr << e.what();
    }
    
    std::cout << std::endl << BCYA << "*** TEST 2 - UNFINDABLE VALUE ***" << RES << std::endl;
    try{
         ::easyfind(vec, 12);
    }catch (std::exception& e){
        std::cerr << e.what();
    }


    std::cout << std::endl << BYEL << "*** USING A CONST VECTOR ***" << RES << std::endl;
    std::vector<int> tmp;
     for (int i = 0; i < 5; i++)
        tmp.push_back(i);

    const std::vector<int>constVec = tmp;

        std::cout << BCYA << "*** TEST 1 - FINDABLE VALUE ***" << RES << std::endl;
    try{
         ::easyfind(constVec, 3);
    }catch (std::exception& e){
        std::cerr << e.what();
    }
    
    std::cout << std::endl << BCYA << "*** TEST 2 - UNFINDABLE VALUE ***" << RES << std::endl;
    try{
         ::easyfind(constVec, 100);
    }catch (std::exception& e){
        std::cerr << e.what();
    }

    
    std::cout << std::endl << BYEL << "*** USING A LIST ***" << RES << std::endl;
    std::list<int> lst;
    for (int i = 0; i < 5; i++)
        lst.push_back(i * 5);
        
    std::cout << BCYA << "*** TEST 1 - FINDABLE VALUE ***" << RES << std::endl;
    try{
         ::easyfind(lst, 10);
    }catch (std::exception& e){
        std::cerr << e.what();
    }
    
    std::cout << std::endl << BCYA << "*** TEST 2 - UFINDABLE VALUE ***" << RES << std::endl;
    try{
         ::easyfind(lst, 13);
    }catch (std::exception& e){
        std::cerr << e.what();
    }
    return 0;
}