#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

// Avant les autres inclusions ou déclarations
class Form;

#include <iostream>
#include <exception>
#include <string>
#include "Form.hpp"

class Bureaucrat
{
    private:
        std::string const _name;
        unsigned int    _grade;
    public:
        Bureaucrat();
        Bureaucrat(std::string const name, unsigned int grade);
        Bureaucrat(Bureaucrat const &copy);
        Bureaucrat &operator=( const Bureaucrat &a );
        ~Bureaucrat();

        void    signForm(Form &form)   const;


        //Getter
        std::string const   getName() const;
        unsigned int    getGrade() const; 

        //Manipulate Grade
        void    validateGrade(unsigned int new_grade);
        void    decrementGrade();
        void    incrementGrade();

        //Exception
        class GradeTooLowException: public std::exception{
                public:
                    const char *what() const throw();
        };

        class GradeTooHighException: public std::exception {
                public:
                    const char *what() const throw();
        };

};

std::ostream    &operator<<( std::ostream &os, const Bureaucrat &to_display );

#endif