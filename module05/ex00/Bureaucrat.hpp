#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include <string>

class Bureaucrat
{
	private:
		std::string const	_name;
		int					_grade;
	
	public:
		Bureaucrat();
		Bureaucrat(std::string const name, int grade);
		Bureaucrat(Bureaucrat const &copy);
		Bureaucrat &operator=( const Bureaucrat &a );
		~Bureaucrat();

		//Getter
		std::string const	getName() const;
		int					getGrade() const; 

		//Manipulate Grade
		void	validateGrade(int new_grade);
		void	decrementGrade();
		void	incrementGrade();

		//Exception
		class GradeTooLowException: public std::exception
		{
				public:
					const char *what() const throw();
		};

		class GradeTooHighException: public std::exception
		{
				public:
					const char *what() const throw();
		};

};

std::ostream &operator<<( std::ostream &os, const Bureaucrat &to_display );

#endif