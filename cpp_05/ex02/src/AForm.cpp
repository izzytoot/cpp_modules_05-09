/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:47:50 by isabeltooti       #+#    #+#             */
/*   Updated: 2025/09/11 18:43:04 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"

/******************************************************************************/
/*                  Constructors, Copy Constructor, Destructor                 */
/******************************************************************************/
AForm::AForm(): _name("Nameless"), _signed(false), _gradeS(150), _gradeE(150){
	std::cout << BGRN
			  << "Default AForm was constructed."
			  << RES << std::endl;
}

AForm::AForm(const std::string name, const int gradeS, const int gradeE)
	: _name(name), _signed(false), _gradeS(gradeS), _gradeE(gradeE){
    if (this->_gradeS < 1 || this->_gradeE < 1)
        throw AForm::GradeTooHighException();
    else if (this->_gradeS > 150 || this->_gradeE > 150)
        throw AForm::GradeTooLowException();
    std::cout << BGRN
			  << "AForm with name and grades was constructed."
			  << RES << std::endl;
}
 
AForm::AForm(const AForm& src)
	: _name(src._name), _signed(src._signed), _gradeS(src._gradeS), _gradeE(src._gradeE){
	std::cout << BGRN 
              << "AForm was copied and constructed" 
              << RES << std::endl;
}

AForm::~AForm(){
	std::cout << BRED
			  << this->_name
			  << " was destroyed" 
              << RES << std::endl;
}

/******************************************************************************/
/*                                Operators                                   */
/******************************************************************************/

AForm& AForm::operator= (const AForm& src){
	if (this != &src){
		if (this->_name != src._name || this->_gradeS != src._gradeS || this->_gradeE != src._gradeE)
			std::cout << RED << "Invalid copy assignment." << RES << std::endl;
		else{
			this->_signed = src._signed;
			std::cout << BYEL 
              << "AForm was copied with operator" 
              << RES << std::endl;
		}
	}
    return *this;
}

std::ostream& operator<< (std::ostream& output, AForm& aform){
    output << BYEL << "AForm name: " << RES << aform.getName() << std::endl
           << BYEL << "Is signed: " << RES << (aform.isSigned() ? "true" : "false") << std::endl
           << BYEL << "Signing Grade: " << RES << aform.getGradeS() << std::endl
           << BYEL << "Executable grade: " << RES << aform.getGradeE();
    return output;
}

/******************************************************************************/
/*                              Member Functions                              */
/******************************************************************************/

const std::string AForm::getName() const{
    return this->_name;
}

bool AForm::isSigned(){
    return this->_signed;
}

int AForm::getGradeS() const{
    return this->_gradeS;
}

int AForm::getGradeE() const{
    return this->_gradeE;
}

void AForm::beSigned(const Bureaucrat& bureaucrat){
    if (bureaucrat.getGrade() <= this->_gradeS){
         this->_signed = true;
    }
    else
        throw AForm::GradeTooLowException();
}

void AForm::checkBeforeExecution(const Bureaucrat& executor) const{
	if (!this->_signed)
		throw FormNotSignedException();
	if (executor.getGrade() > this->_gradeE)
		throw Bureaucrat::GradeTooLowException();
}

void AForm::execute(const Bureaucrat& executor) const{
	checkBeforeExecution(executor); //common check for every form
	specificExecution(); //specific behaviour of each form
}

const char* AForm::GradeTooHighException::what() const throw(){
	return "\033[0;31mgrade too hig.\033[0m";
}

const char* AForm::GradeTooLowException::what() const throw(){
    return "\033[0;31mgrade too low.\033[0m";
}

const char* AForm::FormNotSignedException::what() const throw(){
    return "\033[0;31mform not being signed yet.\033[0m";
}