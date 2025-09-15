/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabeltootill <isabeltootill@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 16:37:20 by isabeltooti       #+#    #+#             */
/*   Updated: 2025/09/15 20:29:15 by isabeltooti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Data.hpp"
#include "../inc/Serializer.hpp"

int main(void){
    std::cout << std::endl << BCYA << "********* TEST 1 *********" << RES << std::endl;
    Data data1;
    
    std::cout << BYEL << "Original address: " << RES << &data1 << std::endl;
    
    uintptr_t ptr1 = Serializer::serialize(&data1); 
    std::cout << BYEL << "Serialized value: " << RES << ptr1 << std::endl;
    
    Data* data2 = Serializer::deserialize(ptr1);
    if (data2 == &data1)
        std::cout << BYEL << "Deserialized value: " << RES << data2 << std::endl;
    else
        std::cout << RED << "Deserialization failed." << RES << std::endl;

    std::cout << std::endl << BCYA << "********* TEST 2 - with pointer *********" << RES << std::endl;
    Data* data3 = new Data;
    
    std::cout << BYEL << "Original address: " << RES << data3 << std::endl;
    
    uintptr_t ptr2 = Serializer::serialize(data3); 
    std::cout << BYEL << "Serialized value: " << RES << ptr2 << std::endl;
    
    Data* data4 = Serializer::deserialize(ptr2);
    if (data4 == data3)
        std::cout << BYEL << "Deserialized value: " << RES << data4 << std::endl;
    else
        std::cout << RED << "Deserialization failed." << RES << std::endl;

    std::cout << std::endl << BCYA << "********* TEST 3 - with value in Data *********" << RES << std::endl;
    Data* data5 = new Data;
    data5->setInfo("Isabel");

    std::cout << BYEL << "Original _info: " << RES << data5->getInfo() << std::endl;
    std::cout << BYEL << "Original address: " << RES << data5 << std::endl;
    
    uintptr_t ptr3 = Serializer::serialize(data5);
    std::cout << BYEL << "Serialized value: " << RES << ptr3 << std::endl;    

    Data* data6 = Serializer::deserialize(ptr3);
    if (data6 == data5){
        std::cout << BYEL << "Deserialized value: " << RES << data6 << std::endl;
        
        std::cout << std::endl << BCYA << "* Changing _info value on deserialized ptr *" << RES << std::endl;
        data6->setInfo("Filipe");
        std::cout << BYEL << "New _info on deserialized ptr: " << RES << data6->getInfo() << std::endl;
        std::cout << BYEL << "New _info on original ptr: " << RES << data5->getInfo() << std::endl;
    }
    else
        std::cout << RED << "Deserialization failed." << RES << std::endl;
    
    std::cout << std::endl;
    delete data3;
    delete data5;

    return 0;
}