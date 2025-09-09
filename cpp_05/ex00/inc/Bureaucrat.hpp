/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 13:44:45 by icunha-t          #+#    #+#             */
/*   Updated: 2025/09/08 16:45:37 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iomanip>
#include <iostream>

#define RED "\033[0;31m"
#define GRN "\033[0;32m"  
#define YEL "\033[0;33m"
#define CYA "\033[36m" 
#define BRED "\033[31;1m"
#define BGRN "\033[32;1m"
#define BYEL "\033[33;1m"
#define BCYA "\033[36;1m"
#define RES "\033[0m"

class Bureaucrat{
	private:
		const std::string _name;
		int _grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& src);

		Bureaucrat& operator= (const Bureaucrat& src);
		
		~Bureaucrat();

		const std::string getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
		
		class GradeTooHighException: public std::exception{ //nested class so we know the error comes from Bureaucrat
			public:
				virtual const char* what() const throw(); //const throw guarantees that this function won't throw an exception
		};
		
		class GradeTooLowException: public std::exception{
			public:
				virtual const char* what() const throw();
		};
};

//overload operator << returns ad ostream (output) with parts of object b (Bureaucrat)
//writing to output from b
std::ostream& operator<< (std::ostream& output, const Bureaucrat& b);

#endif
