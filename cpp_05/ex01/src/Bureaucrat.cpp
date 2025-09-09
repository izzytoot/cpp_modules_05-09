/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabeltootill <isabeltootill@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 13:44:26 by icunha-t          #+#    #+#             */
/*   Updated: 2025/09/09 20:17:07 by isabeltooti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

/******************************************************************************/
/*                  Constructors, Copy Constructor, Destructor                 */
/******************************************************************************/
Bureaucrat::Bureaucrat(): _name("Nameless"), _grade(150){
	std::cout << BGRN
			  << "Default Bureaucrat was constructed."
			  << RES << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name){
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	this->_grade = grade;
	std::cout << BGRN
			  << "Bureaucrat with name \""
			  << name
			  << "\" and grade \""
			  << grade
			  << "\" was constructed."
			  << RES << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src): _name(src._name), _grade(src._grade){
	std::cout << BGRN 
              << "Bureaucrat was copied and constructed" 
              << RES << std::endl;
}

Bureaucrat::~Bureaucrat(){
	std::cout << BRED 
              << "Bureaucrat was destroyed" 
              << RES << std::endl;
}

/******************************************************************************/
/*                                Operators                                   */
/******************************************************************************/

Bureaucrat& Bureaucrat::operator= (const Bureaucrat& src){
	if (this != &src){
		this->_grade = src._grade;
	}
	std::cout << BYEL 
              << "Bureaucrat was copied with operator" 
              << RES << std::endl;
    return *this;
}

std::ostream& operator<< (std::ostream& output, const Bureaucrat& b){
	output << BYEL << b.getName() << ", bureaucrat grade " << b.getGrade() << "." << RES;
	return output;
}

/******************************************************************************/
/*                              Member Functions                              */
/******************************************************************************/

const std::string Bureaucrat::getName() const{
	return this->_name;
}

int Bureaucrat::getGrade() const{
	return this->_grade;
}

void Bureaucrat::incrementGrade(){
	if (this->_grade <= 1)
		throw GradeTooHighException();
	else{
		std::cout << "incrementing... " << std::endl;
		this->_grade--;	
	}	
}

void Bureaucrat::decrementGrade(){
	if (this->_grade >= 150)
		throw GradeTooLowException();
	else{
		std::cout << "decrementing... " << std::endl;
		this->_grade++;	
	}	
}

void Bureaucrat::signForm(Form& form){
	try{
		form.beSigned(*this);
		std::cout << BCYA 
				  << "Bureaucrat " << this->getName() 
				  << " signed " << form.getName() << "." 
				  << RES << std::endl;
	}
	catch(std::exception &e){
		std::cout << RED 
				  << this->getName() 
				  << " couldn't sign " << form.getName() 
				  << " due to " << e.what()
				  << RES << std::endl;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
	return "\033[0;31mBUREAUCRAT ERROR: grade too high (< 1).\033[0m";
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
	return "\033[0;31mBUREAUCRAT ERROR: grade too low (> 150).\033[0m";
}
