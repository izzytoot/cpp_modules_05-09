/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 16:18:22 by icunha-t          #+#    #+#             */
/*   Updated: 2025/09/11 17:06:45 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern{
	public:
		Intern();
		Intern(const Intern& src);

		Intern& operator= (const Intern& src);
		
		~Intern();
		
		AForm* makeForm(std::string formName, std::string formTarget);
		
		class InternException: public std::exception{
			public:
				virtual const char * what() const throw();
		};
};
