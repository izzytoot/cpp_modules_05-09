/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 10:40:26 by icunha-t          #+#    #+#             */
/*   Updated: 2025/09/10 18:56:57 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

#warning "Including ShrubberyCreationForm.hpp"

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
		void specificExecution() const;
		void printTree(std::ostream& output) const;
};

#endif