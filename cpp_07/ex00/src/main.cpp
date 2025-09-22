/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabeltootill <isabeltootill@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:17:56 by icunha-t          #+#    #+#             */
/*   Updated: 2025/09/21 14:21:33 by isabeltooti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/Templates.hpp"

int main(){	
    std::cout << std::endl << BCYA << "********* TEST 1 - SWAP *********" << RES << std::endl;
	
	std::cout << std::endl << BCYA << "* with ints *" << RES << std::endl;
	int x = 5;
	int y = 10;
	std::cout << BYEL << "Before swap: " << RES 
			  << "x = " << x 
			  << "; y = " << y 
			  << std::endl;
	::swap(x, y);
	std::cout << BYEL << "After swap: " << RES 
			  << "x = " << x 
			  << "; y = " << y 
			  << std::endl;
			  
	std::cout << std::endl << BCYA << "* with chars *" << RES << std::endl;
	char a = 'a';
	char b = 'b';
	std::cout << BYEL << "Before swap: " << RES 
			  << "a = " << a 
			  << "; b = " << b 
			  << std::endl;
	::swap(a, b);
	std::cout << BYEL << "After swap: " << RES 
			  << "a = " << a 
			  << "; b = " << b
			  << std::endl;
			  
	std::cout << std::endl << BCYA << "* with strings *" << RES << std::endl;
	std::string str1 = "hello";
	std::string str2 = "goodbye";
	std::cout << BYEL << "Before swap: " << RES 
			  << "str1 = " << str1 
			  << "; str2 = " << str2
			  << std::endl;
	::swap(str1, str2);
	std::cout << BYEL << "After swap: " << RES 
			  << "str1 = " << str1 
			  << "; str2 = " << str2
			  << std::endl;

    std::cout << std::endl << BCYA << "********* TEST 2 - MIN *********" << RES << std::endl;
	std::cout << BYEL << "values: " << RES << "x = " << x << "; y = " << y << std::endl
			  << BYEL << "min is: " << RES << ::min(x, y)
			  << std::endl;
			  
    std::cout << std::endl << BCYA << "********* TEST 3 - MAX *********" << RES << std::endl;
	std::cout << BYEL << "values: " << RES << "x = " << x << "; y = " << y << std::endl
			  << BYEL << "max is: " << RES << ::max(x, y)
			  << std::endl;
			  
	return 0;
}

//subject main:
// int main( void ) {
// 	int a = 2;
// 	int b = 3;
// 	::swap( a, b );
// 	std::cout << "a = " << a << ", b = " << b << std::endl;
// 	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
// 	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
// 	std::string c = "chaine1";
// 	std::string d = "chaine2";
// 	::swap(c, d);
// 	std::cout << "c = " << c << ", d = " << d << std::endl;
// 	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
// 	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
// 	return 0;
// }

// complex types
// class Awesome {
// public:
//     Awesome(int n) : _n(n) {}
//     bool operator==(Awesome const& other) const { return this->_n == other._n; }
//     bool operator!=(Awesome const& other) const { return this->_n != other._n; }
//     bool operator>(Awesome const& other) const { return this->_n > other._n; }
//     bool operator<(Awesome const& other) const { return this->_n < other._n; }
//     bool operator>=(Awesome const& other) const { return this->_n >= other._n; }
//     bool operator<=(Awesome const& other) const { return this->_n <= other._n; }

//     int getN() const { return _n; }

// private:
//     int _n;
// };

// std::ostream& operator<<(std::ostream& o, Awesome const& a) {
//     o << a.getN();
//     return o;
// }

// int main() {
//     Awesome a(2), b(4);

//     ::swap(a, b);
//     std::cout << "a = " << a << ", b = " << b << std::endl;

//     std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
//     std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

//     return 0;
// }