/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:28:19 by icunha-t          #+#    #+#             */
/*   Updated: 2025/09/11 14:37:52 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <fstream>

class PresidentialPardonForm: public AForm{
	private:
		std::string _target;
		
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& src);
		
		PresidentialPardonForm& operator= (const PresidentialPardonForm& src);
		
		~PresidentialPardonForm();

		std::string getTarget();
		void specificExecution() const; //override
};