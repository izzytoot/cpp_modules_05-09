/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 10:40:44 by icunha-t          #+#    #+#             */
/*   Updated: 2025/09/10 16:49:13 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RobotomyRequestForm.hpp"

/******************************************************************************/
/*                  Constructors, Copy Constructor, Destructor                 */
/******************************************************************************/

RobotomyRequestForm::RobotomyRequestForm(): AForm("noTarget", 145, 137), _target("noTarget"){
	std::cout << BGRN
			  << "Default RobotomyRequestForm was constructed."
			  << RES << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm(target, 145, 137), _target(target){
	std::cout << BGRN
			  << "RobotomyRequestForm with target \"" << target
			  << "\" was constructed."
			  << RES << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src): AForm(src.getName(), src.getGradeS(), src.getGradeE()){
	this->_target = src._target;
	std::cout << BGRN
			  << "RobotomyRequestForm with target \"" << _target
			  << "\" was copied and constructed."
			  << RES << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(){
	std::cout << BRED
			  << "RobotomyRequestForm with target \"" << this->_target
			  << "\" was destroyed."
			  << RES << std::endl;
}

/******************************************************************************/
/*                                Operators                                   */
/******************************************************************************/

RobotomyRequestForm& RobotomyRequestForm::operator= (const RobotomyRequestForm& src){
	if (this != &src){
		this->_target = src._target;
	}
	std::cout << BGRN
			  << "RobotomyRequestForm with target \"" << _target
			  << "\" was copied with operator."
			  << RES << std::endl;
	return *this;
}

/******************************************************************************/
/*                              Member Functions                              */
/******************************************************************************/

std::string RobotomyRequestForm::getTarget(){
	return this->_target;
}

void RobotomyRequestForm::specificExecution() const{
	std::cout << BCYA
			  << "trrr...chrrr...brrrr...prrr"
			  << std::endl;
	if (std::rand() % 2){
		std::cout << BCYA
				  << this->_target
			  	  << " has been robotomized!"
				  << RES << std::endl;	
	} else{
		std::cout << RED
				  << "Robotomization of "
				  << this->_target
			  	  << " has failed!"
				  << RES << std::endl;	
	}
}
