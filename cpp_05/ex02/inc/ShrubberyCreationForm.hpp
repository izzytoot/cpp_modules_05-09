/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 10:40:26 by icunha-t          #+#    #+#             */
/*   Updated: 2025/09/11 14:37:52 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm: public AForm{
	private:
		std::string _target;
		
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& src);
		
		ShrubberyCreationForm& operator= (const ShrubberyCreationForm& src);
		
		~ShrubberyCreationForm();

		std::string getTarget();
		void specificExecution() const; //override
		void printTree(std::ostream& output);
};