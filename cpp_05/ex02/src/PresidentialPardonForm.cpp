/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 10:40:23 by icunha-t          #+#    #+#             */
/*   Updated: 2025/09/11 14:26:20 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PresidentialPardonForm.hpp"

/******************************************************************************/
/*                  Constructors, Copy Constructor, Destructor                 */
/******************************************************************************/

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("noTarget", 145, 137), _target("noTarget"){
	std::cout << BGRN
			  << "Default PresidentialPardonForm was constructed."
			  << RES << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm(target, 145, 137), _target(target){
	std::cout << BGRN
			  << "PresidentialPardonForm with target \"" << target
			  << "\" was constructed."
			  << RES << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src): AForm(src.getName(), src.getGradeS(), src.getGradeE()){
	this->_target = src._target;
	std::cout << BGRN
			  << "PresidentialPardonForm with target \"" << _target
			  << "\" was copied and constructed."
			  << RES << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(){
	std::cout << BRED
			  << "PresidentialPardonForm with target \"" << this->_target
			  << "\" was destroyed."
			  << RES << std::endl;
}

/******************************************************************************/
/*                                Operators                                   */
/******************************************************************************/

PresidentialPardonForm& PresidentialPardonForm::operator= (const PresidentialPardonForm& src){
	if (this != &src){
		this->_target = src._target;
	}
	std::cout << BGRN
			  << "PresidentialPardonForm with target \"" << _target
			  << "\" was copied with operator."
			  << RES << std::endl;
	return *this;
}

/******************************************************************************/
/*                              Member Functions                              */
/******************************************************************************/

std::string PresidentialPardonForm::getTarget(){
	return this->_target;
}

void PresidentialPardonForm::specificExecution() const{
	std::cout << BCYA
			  << this->_target 
			  << "has been pardoned by Zaphod Beeblebrox." 
			  << RES << std::endl;
}