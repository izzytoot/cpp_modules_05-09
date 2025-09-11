/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 10:35:51 by icunha-t          #+#    #+#             */
/*   Updated: 2025/09/11 14:40:27 by icunha-t         ###   ########.fr       */
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

	ShrubberyCreationForm form1("tree 1");
	AForm* form2 = new ShrubberyCreationForm("tree 2"); 
	form2->specificExecution();
	
	delete form2;
	return 0;
}