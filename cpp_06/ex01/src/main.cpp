/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabeltootill <isabeltootill@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 16:37:20 by isabeltooti       #+#    #+#             */
/*   Updated: 2025/09/16 11:04:39 by isabeltooti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Data.hpp"
#include "../inc/Serializer.hpp"

int main(void){
    std::cout << std::endl << BCYA << "********* TEST 1 - STACK ALOCATION *********" << RES << std::endl;
    Data data1;
    
    std::cout << BYEL << "Original address: " << RES << &data1 << std::endl;
    
    uintptr_t ptr1 = Serializer::serialize(&data1); 
    std::cout << BYEL << "Serialized value: " << RES << ptr1 << std::endl;
    
    Data* data2 = Serializer::deserialize(ptr1);
    if (data2 == &data1)
        std::cout << BYEL << "Deserialized value: " << RES << data2 << std::endl;
    else
        std::cout << RED << "Deserialization failed." << RES << std::endl;
    
    std::cout << std::endl << BCYA << "* Setting _info value for data2 *" << RES << std::endl;
    data2->setInfo("Santi");
    std::cout << BYEL << "_info of data2: " << RES << data2->getInfo() << std::endl;
    std::cout << BYEL << "_info of data1: " << RES << data1.getInfo() << std::endl;
    std::cout << std::endl << BCYA << "* Changing _info value on data1 *" << RES << std::endl;
    data1.setInfo("Jack");
    std::cout << BYEL << "_info of data1 after change: " << RES << data1.getInfo() << std::endl;
    std::cout << BYEL << "_info of data2 after change: " << RES << data2->getInfo() << std::endl;
    
    std::cout << std::endl << BCYA << "********* TEST 2 - HEAP ALOCATION *********" << RES << std::endl;
    Data* data3 = new Data;
    
    std::cout << BYEL << "Original address: " << RES << data3 << std::endl;
    
    uintptr_t ptr2 = Serializer::serialize(data3); 
    std::cout << BYEL << "Serialized value: " << RES << ptr2 << std::endl;
    
    Data* data4 = Serializer::deserialize(ptr2);
    if (data4 == data3)
        std::cout << BYEL << "Deserialized value: " << RES << data4 << std::endl;
    else
        std::cout << RED << "Deserialization failed." << RES << std::endl;

    std::cout << std::endl << BCYA << "* Setting _info value for data4 *" << RES << std::endl;
    data4->setInfo("Sushi");
    std::cout << BYEL << "_info of data4: " << RES << data4->getInfo() << std::endl;
    std::cout << BYEL << "_info of data3: " << RES << data3->getInfo() << std::endl;
    
    std::cout << std::endl << BCYA << "* Changing _info value for data3 *" << RES << std::endl;
    data3->setInfo("Quiwi");
    std::cout << BYEL << "_info of data3: " << RES << data3->getInfo() << std::endl;
    std::cout << BYEL << "_info of data4: " << RES << data4->getInfo() << std::endl;
    
    std::cout << std::endl;
    if (data3) delete data3;
    
    return 0;
}