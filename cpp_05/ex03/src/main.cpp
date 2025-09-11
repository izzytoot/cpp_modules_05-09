/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 10:35:51 by icunha-t          #+#    #+#             */
/*   Updated: 2025/09/11 17:27:01 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/Intern.hpp"
#include <cstdlib>
#include <ctime>

int main(){
	srand(time(NULL));
	
	std::cout << std::endl << BYEL
			  << "************ CREATING INTERN, BUREAUCRAT AND FORMS ************"
			  << RES << std::endl;
			  
	Intern randomIntern;
	Bureaucrat isabel("Isabel", 1);
	AForm* form1;
	AForm* form2;
	AForm* form3;
	AForm* form4;
	
	std::cout << std::endl << BYEL
			  << "************ TESTING MAKEFORM... ************"
			  << RES << std::endl;
	std::cout << std::endl << BYEL
			  << "*** ... WITH INVALID NAME ***"
			  << RES << std::endl;
	try{
		form1 = randomIntern.makeForm("weird name", "target");
	}catch(std::exception& e){
		std::cout << e.what() << std::endl;
		form1 = NULL;
	}

	std::cout << std::endl << BYEL
			  << "*** ... SHRUBBERY WITH VALID NAME ***"
			  << RES << std::endl;
	try{
		form2 = randomIntern.makeForm("Shrubbery", "drawTree");
		isabel.signForm(*form2);
		isabel.executeForm(*form2);
	}catch(std::exception& e){
		std::cout << e.what() << std::endl;
		form2 = NULL;
	}
	
	std::cout << std::endl << BYEL
			  << "*** ... ROBOT WITH VALID NAME ***"
			  << RES << std::endl;
	try{
		form3 = randomIntern.makeForm("Robot", "robotize");
		isabel.signForm(*form3);
		isabel.executeForm(*form3);
	}catch(std::exception& e){
		std::cout << e.what() << std::endl;
		form3 = NULL;
	}

	std::cout << std::endl << BYEL
			  << "*** ... PRESIDENTIAL WITH VALID NAME ***"
			  << RES << std::endl;
	try{
		form4 = randomIntern.makeForm("President", "pardon");
		isabel.signForm(*form4);
		isabel.executeForm(*form4);
	}catch(std::exception& e){
		std::cout << e.what() << std::endl;
		form4 = NULL;
	}
			  
	std::cout << std::endl << BYEL
			  << "************ SO LONG SU#@&RS ************"
			  << RES << std::endl;
	if(form1) delete form1;
	if(form2) delete form2;
	if(form3) delete form3;
	if(form4) delete form4;
	
	return 0;
}