/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 10:35:51 by icunha-t          #+#    #+#             */
/*   Updated: 2025/09/11 14:05:11 by icunha-t         ###   ########.fr       */
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

	// ShrubberyCreationForm form1("tree");
	AForm* form = new ShrubberyCreationForm("tree"); 
	form->specificExecution();
	
	return 0;
}