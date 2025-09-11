/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 10:35:51 by icunha-t          #+#    #+#             */
/*   Updated: 2025/09/11 16:02:15 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include <cstdlib>
#include <ctime>

int main(){
	srand(time(NULL)); // allows std::rand() to generate different results each time

	std::cout << std::endl << BYEL
			  << "************ TESTING FORM CREATION, << OPERATOR AND INVALID BUREAUCRATS ************"
			  << RES << std::endl;
			  
	ShrubberyCreationForm form1("tree_1");
	std::cout << form1 << std::endl;
	
	std::cout << std::endl;
	AForm* form2 = new ShrubberyCreationForm("tree_2"); //ceation via pointer tests polymorphism and destructor
	std::cout << *form2 << std::endl;
	
	std::cout << std::endl;
	try{
		Bureaucrat nobody("Nobody", 0);
	} catch(std::exception& e){
		std::cout << RED << "BUREAUCRAT CREATION ERROR: " << RES << e.what() << std::endl;
	}

	std::cout << std::endl << BYEL
			  << "************ TESTING SHRUBBER EXECUTION ************"
			  << RES << std::endl;
	Bureaucrat jack("Jack", 20);
	Bureaucrat santi("Santi", 150);
	Bureaucrat quiwi("Quiwi", 140);

	std::cout << std::endl;
	try{
		jack.executeForm(form1);
	} catch(std::exception& e){
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	try{
		jack.signForm(form1);
		jack.executeForm(form1);
	} catch(std::exception& e){
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	try{
		santi.signForm(form1);
		santi.executeForm(form1);
	} catch(std::exception& e){
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	try{
		quiwi.signForm(form1);
		quiwi.executeForm(form1);
	} catch(std::exception& e){
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl << BYEL
			  << "************ TESTING ROBOTOMYZATION ************"
			  << RES << std::endl;
	
	RobotomyRequestForm form3("Robot");
	Bureaucrat isabel("Isabel", 20);
	Bureaucrat philip("Philip", 90);
	Bureaucrat filipe("Filipe", 50);
	
	std::cout << std::endl;
	for(int i = 0; i < 10; i++){
		try{
			isabel.signForm(form3);
			isabel.executeForm(form3);
		} catch(std::exception& e){
			std::cout << e.what() << std::endl;
		}	
	}
	std::cout << std::endl;
	try{
		philip.signForm(form3);
		philip.executeForm(form3);
	} catch(std::exception& e){
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try{
		filipe.signForm(form3);
		filipe.executeForm(form3);
	} catch(std::exception& e){
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << BYEL
			  << "************ TESTING PRESIDENTIAL PARDON ************"
			  << RES << std::endl;
	PresidentialPardonForm form4("Pardon");
	Bureaucrat president("President", 1);
	Bureaucrat filipeAgain(filipe);
	Bureaucrat isabelAgain(isabel);
	
	std::cout << std::endl;
	try{
		filipe.signForm(form4);
		filipe.executeForm(form4);
	} catch(std::exception& e){
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	try{
		isabel.signForm(form4);
		isabel.executeForm(form4);
	} catch(std::exception& e){
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	try{
		president.signForm(form4);
		president.executeForm(form4);
	} catch(std::exception& e){
		std::cout << e.what() << std::endl;
	}
			  
	std::cout << std::endl << BYEL
			  << "************ SO LONG SU#$&RS ************"
			  << RES << std::endl;
	delete form2;
	return 0;
}