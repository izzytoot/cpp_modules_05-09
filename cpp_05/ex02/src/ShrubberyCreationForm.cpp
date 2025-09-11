/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 10:40:44 by icunha-t          #+#    #+#             */
/*   Updated: 2025/09/11 14:39:08 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ShrubberyCreationForm.hpp"

/******************************************************************************/
/*                  Constructors, Copy Constructor, Destructor                 */
/******************************************************************************/

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("noTarget", 145, 137), _target("noTarget"){
	std::cout << BGRN
			  << "Default ShrubberyCreationForm was constructed."
			  << RES << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm(target, 145, 137), _target(target){
	std::cout << BGRN
			  << "ShrubberyCreationForm with target \"" << target
			  << "\" was constructed."
			  << RES << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src)
	: AForm(src.getName(), src.getGradeS(), src.getGradeE()){
	this->_target = src._target;
	std::cout << BGRN
			  << "ShrubberyCreationForm with target \"" << _target
			  << "\" was copied and constructed."
			  << RES << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
	std::cout << BRED
			  << "ShrubberyCreationForm with target \"" << this->_target
			  << "\" was destroyed."
			  << RES << std::endl;
}

/******************************************************************************/
/*                                Operators                                   */
/******************************************************************************/

ShrubberyCreationForm& ShrubberyCreationForm::operator= (const ShrubberyCreationForm& src){
	if (this != &src){
		this->_target = src._target;
	}
	std::cout << BGRN
			  << "ShrubberyCreationForm with target \"" << _target
			  << "\" was copied with operator."
			  << RES << std::endl;
	return *this;
}

/******************************************************************************/
/*                              Member Functions                              */
/******************************************************************************/

std::string ShrubberyCreationForm::getTarget(){
	return this->_target;
}

void ShrubberyCreationForm::specificExecution() const{
	std::string fileName = this->_target + "_shrubbery";
	std::ofstream outFile(fileName.c_str());
	if (!outFile) {
        std::cerr << "Error: could not open file " << fileName << std::endl;
        return;
  	}
	outFile << "       _-_       " << std::endl;
    outFile << "    /~~   ~~\\   " << std::endl;
    outFile << " /~~         ~~\\" << std::endl;
    outFile << "{               }" << std::endl;
    outFile << " \\  _-     -_  /" << std::endl;
    outFile << "   ~  \\\\ //  ~ " << std::endl;
    outFile << "_- -   | | _- _ " << std::endl;
    outFile << "  _ -  | |   -_ " << std::endl;
    outFile << "      // \\\\    " << std::endl;
}
