#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

class AForm;

#include <exception>
#include <iostream>
#include <string>
#include "AForm.hpp"

class Bureaucrat
{
	private:
		std::string const	_name;
		int					_grade;
	
	public:
		Bureaucrat();
		Bureaucrat(std::string const name, int grade);
		Bureaucrat(const Bureaucrat& toCopy);
		Bureaucrat &operator=(const Bureaucrat& a);
		~Bureaucrat();

		//Getter
		std::string const getName() const;
		int getGrade() const;

		//Methode
		void validateGrade(int new_grade);
		void decrementGrade();
		void incrementGrade();
		void signForm(AForm& form) const;
		void executeForm(const AForm& form) const;

		//Exception
		 class GradeTooLowException: public std::exception {
			public:
				const char *what() const throw(); 
		};
		
		class GradeTooHighException: public std::exception {
			public:
				const char *what() const throw(); 
		};
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat& toDisplay);

#endif