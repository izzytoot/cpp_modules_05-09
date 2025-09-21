/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 11:44:09 by isabeltooti       #+#    #+#             */
/*   Updated: 2025/09/17 16:38:29 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Base.hpp"
#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"

/******************************************************************************/
/*                               Destructor                                   */
/******************************************************************************/
Base::~Base(){}

/******************************************************************************/
/*                               Free Functions                               */
/******************************************************************************/

Base* generate(){
    int random = std::rand() % 3;

    switch (random){
        case 0: return new A();
        case 1: return new B();
        case 2: return new C();
        default: return NULL;
	}
    return NULL;
}

//when using a ptr(*), dynamic_cast returns NULL on failure, so we can use if/else
void identify(Base* p){
    if (dynamic_cast<A*>(p))
        std::cout << BYEL << "PTR: " << RES << "object is of type A." << RES << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << BYEL << "PTR: " << RES << "object is of type B." << RES << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << BYEL << "PTR: " << RES << "object is of type C." << RES << std::endl;
    else
        std::cout << RED << "ERROR! No type found." << RES << std::endl;
}

//when using a ref(&), dynamic_cast needs to be wraped in a try/catch since it returns an exception (bad_cast&) on failure
void identify(Base& p){    
    try{
        (void)dynamic_cast<A&>(p);
        std::cout << BYEL << "REF: " << RES << "object is of type A." << RES << std::endl;
        return;
    }catch (std::bad_cast&){}
    try{
        (void)dynamic_cast<B&>(p);
        std::cout << BYEL << "REF: " << RES << "object is of type B." << RES << std::endl;
        return;
    }catch (std::bad_cast&){}
    try{
        (void)dynamic_cast<C&>(p);
        std::cout << BYEL << "REF: " << RES << "object is of type C." << RES << std::endl;
        return;
    }catch (std::bad_cast&){}

    std::cout << RED << "ERROR! No type found." << RES << std::endl;
}