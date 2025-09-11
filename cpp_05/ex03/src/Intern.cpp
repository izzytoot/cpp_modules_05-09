/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 16:24:43 by icunha-t          #+#    #+#             */
/*   Updated: 2025/09/11 17:25:03 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"

/******************************************************************************/
/*                  Constructors, Copy Constructor, Destructor                 */
/******************************************************************************/
Intern::Intern(){
	std::cout << BGRN
			  << "Default Intern was constructed."
			  << RES << std::endl;
}

Intern::Intern(const Intern& src){
	*this = src;
	std::cout << BGRN
			  << "Intern was copied and constructed."
			  << RES << std::endl;
}
		
Intern::~Intern(){
	std::cout << BRED
			  << "Intern was destroyed."
			  << RES << std::endl;
}

/******************************************************************************/
/*                                Operators                                   */
/******************************************************************************/

Intern& Intern::operator= (const Intern& src){
	if (this != &src)
		*this = src;
	std::cout << BGRN
			  << "Intern was copied with operator."
			  << RES << std::endl;
	return *this;
}

/******************************************************************************/
/*                              Member Functions                              */
/******************************************************************************/
		
AForm* Intern::makeForm(std::string formName, std::string formTarget){
	int index = -1;
	std::string form[3] = {"Shrubbery", "Robot", "President"};
	
	for(int i = 0; i < 3; i++){
		if (form[i] == formName){
			index = i;
			break;
		}
	}
	if (index != -1)
		std::cout << BCYA 
				  << "Intern creates " 
				  << formName 
				  << RES << std::endl;
	switch(index){
		case 0: return new ShrubberyCreationForm(formTarget);
		case 1: return new RobotomyRequestForm(formTarget);
		case 2: return new PresidentialPardonForm(formTarget);
		default: throw Intern::InternException();
	}
}

const char* Intern::InternException::what() const throw(){
	return "\033[0;31mForm name doesn't exist: Intern can't make form.\033[0m";
}