#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include <string>

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