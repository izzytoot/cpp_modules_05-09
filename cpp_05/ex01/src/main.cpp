/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 13:44:01 by icunha-t          #+#    #+#             */
/*   Updated: 2025/09/11 18:35:01 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"

int main(){
	std::cout << std::endl << BCYA
			  << "************************ TESTS FOR EX00 ************************"
			  << RES << std::endl;
			  
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
			  << "************************ TESTS FOR EX01 ************************"
			  << RES << std::endl;

	std::cout << std::endl << BCYA
			  << "*** CREATING A BUREAUCRAT AND A FORM ***"
			  << RES << std::endl;
	
	Bureaucrat quiwi("Quiwi", 42);
	std::cout << quiwi << std::endl;
	Form form1("Form 1", 20, 20);
	std::cout << form1 << std::endl;

	std::cout << std::endl << BCYA
			  << "*** ATTRIBUTING AN INVALID GRADE TO A FORM ON CONSTRUCTION ***"
			  << RES << std::endl;
	try{
		Form form2("Form 2", 200, 0);
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << BCYA
			  << "*** TESTING BESIGNED() WITH VALID AND INVALID VALUES ***"
			  << RES << std::endl;
	Form form3("Form 3", 50, 50);
	std::cout << form3 << std::endl;
	try{
		form3.beSigned(quiwi);
		std::cout << form3 << std::endl << std::endl;
	} catch (std::exception& e){
		std::cout << RED << quiwi.getName() << " couldn't sign form due to" << e.what() << RES << std::endl;
	}
	Bureaucrat sushi("Sushi", 100);
	std::cout << sushi << std::endl;
	try{
		form3.beSigned(sushi);	
	} catch (std::exception& e){
		std::cout << RED << sushi.getName() << " couldn't sign " << form3.getName() << " due to " << e.what() << RES << std::endl;
	}

	std::cout << std::endl << BCYA
			  << "*** TESTING SIGNFORM() WITH VALID AND INVALID VALUES ***"
			  << RES << std::endl;
	quiwi.signForm(form3);
	sushi.signForm(form3);
	
			  
	std::cout << std::endl << BCYA
			  << "*** SO LONG SU#@&RS ***"
			  << RES << std::endl;
	return 0;
}
