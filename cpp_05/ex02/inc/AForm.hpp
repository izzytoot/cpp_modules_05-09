/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:47:41 by isabeltooti       #+#    #+#             */
/*   Updated: 2025/09/11 14:20:13 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iomanip>
#include <string>
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

class Bureaucrat;

class AForm{
    private:
        const std::string _name;
        bool _signed;
        const int _gradeS;
        const int _gradeE;
        
    public:
        AForm();
        AForm(const std::string name, const int gradeS, const int gradeE);
        AForm(const AForm& src);

        AForm& operator= (const AForm& src);
        
        virtual ~AForm();

        const std::string getName() const;
        bool isSigned();
        int getGradeS() const;
        int getGradeE() const;

        void sign(Bureaucrat const& bureaucrat);
		void checkBeforeExecution(Bureaucrat const& executor) const; //helper to centralize the check
		virtual void execute(const Bureaucrat& executor) const; // public interface for execution
		virtual void specificExecution() const = 0;//makes AForm abstract. To be overriden in the derived classes
        
		class GradeTooHighException: public std::exception{
            public:
                virtual const char* what() const throw();
        };
        
        class GradeTooLowException: public std::exception{
            public:
                virtual const char* what() const throw();
        };

		class FormNotSignedException: public std::exception{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<< (std::ostream& output, AForm& aform);
