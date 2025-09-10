/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 10:35:51 by icunha-t          #+#    #+#             */
/*   Updated: 2025/09/10 18:58:47 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"
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
	
	return 0;
}