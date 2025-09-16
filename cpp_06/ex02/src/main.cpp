/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabeltootill <isabeltootill@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 12:55:14 by isabeltooti       #+#    #+#             */
/*   Updated: 2025/09/16 13:38:55 by isabeltooti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Base.hpp"
#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"

int main(){
    srand(time(NULL));
    
    std::cout << std::endl << BCYA << "********* TEST 1 - CREATING OBJS DIRECTLY AND IDENTIFYING THEM *********" << RES << std::endl;
    A objA;
    B objB;
    C objC;

    std::cout << BCYA << "* Identifying through PTR *" << RES << std::endl;
    identify(&objA); //&objA is passed by pointer (refers to the address of A* objA)
    identify(&objB);
    identify(&objC);
    std::cout << BCYA << "* Identifying through REF *" << RES << std::endl;
    identify(objA); //objA is passed by reference (the object itself)
    identify(objB);
    identify(objC);

    std::cout << std::endl << BCYA << "********* TEST 2 - CREATING RANDOM OBJ AND IDENTIFYING IT *********" << RES << std::endl;
    Base* random = generate();
    std::cout << BCYA << "* Identifying through PTR *" << RES << std::endl;
    identify(random); //random is a Base* so it's being passed as the ptr it is
    std::cout << BCYA << "* Identifying through REF *" << RES << std::endl;
    identify(*random); //the * dereferences random, thus passing the actual object

    std::cout << std::endl << BCYA << "********* TEST 3 - CREATING NULL OBJ AND IDENTIFYING IT *********" << RES << std::endl;
    Base* empty = NULL;
    identify(empty);

    if (random) delete random;
    return 0;
}