#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string name, const std::string target): AForm(name, 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm Default constructor called : " << *this << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& toCopy) : AForm(toCopy), _target(toCopy.getTarget())
{
	std::cout << "ShrubberyCreationForm copy constructor called : " << *this << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm& a)
{
	if (this != &a)
		AForm::operator=(a);
	std::cout << "ShrubberyCreationForm Assignement operator called" << std::endl;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destrucor called" << std::endl;
}

void ShrubberyCreationForm::generateFile() const
{
	std::string new_filename(_target + "_shrubbery");
	std::ofstream flux(new_filename.c_str());
	if (!flux)
		throw std::runtime_error("Failed to open file: " + new_filename);
	
	flux << "               ,@@@@@@@," << std::endl;
	flux << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
	flux << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
	flux << "   ,%&%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
	flux << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
	flux << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
	flux << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
	flux << "       |o|        | |         | |" << std::endl;
	flux << "       |.|        | |         | |" << std::endl;
	flux << "    \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl;

	if (!flux)
		throw std::runtime_error("Failed to write to file: " + new_filename);
	flux.close();
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	try{
		AForm::beExecuted(executor);
	}
	catch(std::exception& e){
		throw ;
	}

	try{
		this->generateFile();
	}
	catch(const std::exception& e){
		throw ;
	}
}

const std::string ShrubberyCreationForm::getTarget() const
{
	return (_target);
}

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& to_display)
{
	os << static_cast<const AForm&>(to_display);
	os << " Target: " << to_display.getTarget();
	return (os);
}