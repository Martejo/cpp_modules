#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		const std::string	_target;
	
	public:
		ShrubberyCreationForm(const std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& toCopy);
		ShrubberyCreationForm& operator=(ShrubberyCreationForm& a);
		virtual ~ShrubberyCreationForm();

		void execute(const Bureaucrat &executor) const;
		void generateFile() const;
		const std::string getTarget() const;
};

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& to_display);


#endif