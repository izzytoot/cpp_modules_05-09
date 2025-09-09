/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabeltootill <isabeltootill@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:47:41 by isabeltooti       #+#    #+#             */
/*   Updated: 2025/09/09 18:43:44 by isabeltooti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iomanip>
#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

#define RED "\033[0;31m"
#define GRN "\033[0;32m"  
#define YEL "\033[0;33m"
#define CYA "\033[36m" 
#define BRED "\033[31;1m"
#define BGRN "\033[32;1m"
#define BYEL "\033[33;1m"
#define BCYA "\033[36;1m"
#define RES "\033[0m"

class Bureaucrat;

class Form{
    private:
        const std::string _name;
        bool _signed;
        const int _gradeS;
        const int _gradeE;
        
    public:
        Form();
        Form(const std::string name, const int gradeS, const int gradeE);
        Form(const Form& src);

        Form& operator= (const Form& src);
        
        ~Form();

        const std::string getName() const;
        bool isSigned();
        int getGradeS() const;
        int getGradeE() const;

        void beSigned(Bureaucrat& bureaucrat);
        
        class GradeTooHighException: public std::exception{
            public:
                virtual const char* what() const throw();
        };
        
        class GradeTooLowException: public std::exception{
            public:
                virtual const char* what() const throw();
        };        
};

std::ostream& operator<< (std::ostream& output, Form& form);

#endif