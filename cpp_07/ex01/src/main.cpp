/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 13:14:07 by icunha-t          #+#    #+#             */
/*   Updated: 2025/09/18 15:06:53 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/iter.hpp"

int main(){

    std::cout << std::endl << BCYA << "********* TEST 1 - ITER WITH INCREMENT *********" << RES << std::endl;

	int array1[3] = {0, 1, 2};

	std::cout << BYEL << "Before iter: " << RES;
	for(int i = 0; i < 3; i++)
		std::cout << array1[i] << " ";
	std:: cout << std::endl;
	::iter(array1, 3, increment);
	std::cout << BYEL << "After iter: " << RES;
	for(int i = 0; i < 3; i++)
		std::cout << array1[i] << " ";
	std:: cout << std::endl;

    std::cout << std::endl << BCYA << "********* TEST 2 - ITER WITH PRINTCHAR *********" << RES << std::endl;
	char array2[3] = {'a', 'b', 'c'};
	std::cout << BYEL << "Printing char array with iter: " << RES;
	::iter(array2, 3, printChar);
	std::cout << std::endl;
	
    std::cout << std::endl << BCYA << "********* TEST 3 - ITER WITH PRINTANYTYPE *********" << RES << std::endl;
	
	std::cout << BCYA << "* with strings *" << RES << std::endl;
	std::string array3[3] = {"one", "two", "three"};
	std::cout << BYEL << "Printing strings with iter: " << RES;
	::iter(array3, 3, printAnyType<std::string>);
	std:: cout << std::endl;
	
	std::cout << std::endl << BCYA << "* with longs *" << RES << std::endl;
	long array4[3] = {1, 2, 3};
	std::cout << BYEL << "Printing longs with iter: " << RES;
	::iter(array4, 3, printAnyType<long>);
	std:: cout << std::endl;
	
	std::cout << std::endl << BCYA << "* with const array of chars *" << RES << std::endl;
	const char array5[3] = {'a', 'b', 'c'};
	std::cout << BYEL << "Printing chars with iter: " << RES;
	::iter(array5, 3, printAnyType<char>);
	std:: cout << std::endl;

    std::cout << std::endl << BCYA << "********* TEST 4 - PRINT, INCREMENT AND PRINT *********" << RES << std::endl;
	int array6[3] = {42, 52, 62};
	std::cout << BYEL << "printAnyType before addOne: " << RES;
	::iter(array6, 3, printAnyType<int>);
	std:: cout << std::endl;
	::iter(array6, 3, increment);
	std::cout << BYEL << "printAnyType after addOne: " << RES;
	::iter(array6, 3, printAnyType<int>);
	std:: cout << std::endl;
	return 0;
}