#ifndef INTERN_HPP
#define INTERN_HPP
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>
#include <iostream>

enum 
{
	ROBOTOMY_REQUEST,
	SHRUBBERY_CREATION,
	PRESIDENTIAL_PARDON
};
class Intern
{
	public : 
	Intern();
	Intern(Intern &toCopy);
	~Intern();
	Intern& operator=(Intern& other);

	unsigned int getFormIndex(const std::string f_name) const;
	AForm	*makeForm(const std::string f_name, const std::string target) const ;

	class BadFormNameException : public std::exception
	{
		public :
			const char* what() const throw();
	};
};

#endif