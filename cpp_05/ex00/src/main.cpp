/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabeltootill <isabeltootill@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 13:44:01 by icunha-t          #+#    #+#             */
/*   Updated: 2025/09/09 16:50:01 by isabeltooti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

int main(){
	
	std::cout << std::endl << BCYA
			  << "*** CREATING A BUREAUCRAT AND USING OVERLOAD OPERATOR << ***"
			  << RES << std::endl;
	Bureaucrat isabel("Isabel", 42);
	std::cout << isabel << std::endl;
	
	std::cout << std::endl << BCYA
			  << "*** TESTING INCREMENT AND DECREMENT ***"
			  << RES << std::endl;
	try{
		isabel.incrementGrade();
	} catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	std::cout << isabel << std::endl;
	try{
		isabel.decrementGrade();
	} 
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	std::cout << isabel << std::endl;

	std::cout << std::endl << BCYA
			  << "*** USING LIMIT GRADES AND TRYING TO INCREMENT AND DECREMENT ***"
			  << RES << std::endl;
	Bureaucrat rodrigo("Rodrigo", 1);
	std::cout << rodrigo << std::endl;
	Bureaucrat filipe("Filipe", 150);
	std::cout << filipe << std::endl;
	try{
		rodrigo.incrementGrade();
	} 
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	try{
		filipe.decrementGrade();
	} 
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl << BCYA
			  << "*** USING AN INVALID GRADE ***"
			  << RES << std::endl;
	try{
		Bureaucrat philip("Philip", 400);
	} 
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl << BCYA
			  << "*** TESTING COPY CONSTRUCTOR - FILIPE INTO JACK ***"
			  << RES << std::endl;
	Bureaucrat jack(filipe);
	std::cout << filipe << std::endl;
	std::cout << jack << std::endl;

	std::cout << std::endl << BCYA
			  << "*** TESTING COPY ASSIGNMENT - JACK INTO SANTI ***"
			  << RES << std::endl;
	Bureaucrat santi = jack;
	std::cout << jack << std::endl;
	std::cout << santi << std::endl;


	std::cout << std::endl << BCYA
			  << "*** SO LONG SU#$&RS ***"
			  << RES << std::endl;
	return 0;
}