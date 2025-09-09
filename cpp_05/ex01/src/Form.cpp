/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabeltootill <isabeltootill@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:47:50 by isabeltooti       #+#    #+#             */
/*   Updated: 2025/09/09 18:43:51 by isabeltooti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Form.hpp"

/******************************************************************************/
/*                  Constructors, Copy Constructor, Destructor                 */
/******************************************************************************/
Form::Form(): _name("Nameless"), _signed(false), _gradeS(150), _gradeE(150){
	std::cout << BGRN
			  << "Default Form was constructed."
			  << RES << std::endl;
}

Form::Form(const std::string name, const int gradeS, const int gradeE): _name(name), _signed(false), _gradeS(gradeS), _gradeE(gradeE){
    if (this->_gradeS < 1 || this->_gradeE < 1)
        throw Form::GradeTooHighException();
    else if (this->_gradeS > 150 || this->_gradeE > 150)
        throw Form::GradeTooLowException();
    std::cout << BGRN
			  << "Form with name and grades was constructed."
			  << RES << std::endl;
}

        
Form::Form(const Form& src): _name(src._name), _signed(src._signed), _gradeS(src._gradeS), _gradeE(src._gradeE){
	std::cout << BGRN 
              << "Form was copied and constructed" 
              << RES << std::endl;
}

Form::~Form(){
	std::cout << BRED 
              << "Form was destroyed" 
              << RES << std::endl;
}

/******************************************************************************/
/*                                Operators                                   */
/******************************************************************************/

Form& Form::operator= (const Form& src){
	if (this != &src){
		this->_signed = src._signed;
	}
	std::cout << BYEL 
              << "Form was copied with operator" 
              << RES << std::endl;
    return *this;
}

std::ostream& operator<< (std::ostream& output, Form& form){
    output << BCYA << "Form name: " << RES << form.getName() << std::endl
           << BCYA << "Is signed: " << RES << (form.isSigned() ? "true" : "false") << std::endl
           << BCYA << "Signing Grade: " << RES << form.getGradeS() << std::endl
           << BCYA << "Executable grade: " << RES << form.getGradeE();
    return output;
}

/******************************************************************************/
/*                              Member Functions                              */
/******************************************************************************/

const std::string Form::getName() const{
    return this->_name;
}

bool Form::isSigned(){
    return this->_signed;
}

int Form::getGradeS() const{
    return this->_gradeS;
}

int Form::getGradeE() const{
    return this->_gradeE;
}

void Form::beSigned(Bureaucrat& bureaucrat){
    if (bureaucrat.getGrade() <= this->_gradeS)
        this->_signed = true;
    else
        throw Form::GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw(){
	return "\033[0;31mFORM ERROR: grade too high (< 1).\033[0m";
}

const char* Form::GradeTooLowException::what() const throw(){
    return "\033[0;31mFORM ERROR: grade too low (> 150).\033[0m";
}