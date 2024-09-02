#ifndef FORM_HPP
#define FORM_HPP

// Avant les autres inclusions ou déclarations
class Bureaucrat;

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExec;
	
	public:
		Form(const std::string name, const int gradeSign, const int gradeExec);
		Form(const Form& toCopy);
		Form& operator=(Form& a);
		~Form();

		const std::string	getName()	const;
		bool				getSigned()	const;
		int					getSignGrade()	const;
		int					getExecGrade()	const;

		void	beSigned(const Bureaucrat& bureaucrat);

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

std::ostream& operator<<( std::ostream& os, const Form& to_display);

#endif