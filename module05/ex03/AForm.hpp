#ifndef AFORM_HPP
#define AFORM_HPP

class Bureaucrat;

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"


class AForm
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int	_gradeToSign;
		const int	_gradeToExec;

	public:
		AForm(const std::string name, const int gradeSign, const int gradeExec);
		AForm(const AForm& toCopy);
		AForm& operator=(AForm& a);
		virtual ~AForm();

		//Getter
		const std::string getName() const;
		bool getSigned() const;
		int getSignGrade() const;
		int getExecGrade() const;

		//Method
		void beSigned(const Bureaucrat& bureaucrat);
		void beExecuted(const Bureaucrat& bureaucrat) const;
		virtual void execute(Bureaucrat const &executor) const = 0;
		virtual const std::string getTarget() const = 0;


		class GradeTooLowException: public std::exception {
			public:
				const char *what() const throw(); 
		};
		
		class GradeTooHighException: public std::exception {
			public:
				const char *what() const throw(); 
		};

		class SignatureException: public std::exception {
			public:
				const char *what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const AForm& to_display);
#endif

