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

    std::cout << "Vector contains: ";
    for (unsigned int i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;

    std::cout << std::endl << BCYA << "*** TEST 1 - FINDABLE VALUE ***" << RES << std::endl;
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

    std::cout << "Vector contains: ";
    for (unsigned int i = 0; i < tmp.size(); i++)
        std::cout << tmp[i] << " ";
    std::cout << std::endl;

    const std::vector<int>constVec = tmp;

        std::cout << std::endl << BCYA << "*** TEST 1 - FINDABLE VALUE ***" << RES << std::endl;
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
    
    std::cout << "List contains: ";
    for (std::list<int>::iterator i = lst.begin(); i != lst.end(); ++i) //iterator because std::list doesn't support [] operator to fetch index element
        std::cout << *i << " ";
    std::cout << std::endl;


    std::cout << std::endl << BCYA << "*** TEST 1 - FINDABLE VALUE ***" << RES << std::endl;
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