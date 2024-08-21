#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern constructor called" << std::endl;
}

Intern::Intern(Intern &toCopy)
{
	std::cout << "Intern copy constructor called" << std::endl;
	if (this != &toCopy)
		*this = toCopy;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

Intern& Intern::operator=(Intern& other)
{
	std::cout << "Intern assignement operator called" << std::endl;
	//Nothing to copy inside intern
	return(other);
}

unsigned int Intern::getFormIndex(std::string f_name) const
{
	std::string forms[3] = 
	{"robotomy request",
	"shrubbery creation",
	"presidential pardon"
	};
	for (size_t i = 0; i < f_name.length(); i++)
		f_name[i] = std::tolower(f_name[i]);
	for (int i = 0; i < 3; i++)
		if (forms[i] == f_name)
			return (i);
	return (-1);
}

AForm	*Intern::makeForm(std::string f_name, const std::string target) const
{
	AForm *new_form = NULL;

	switch(getFormIndex(f_name))
	{
		case ROBOTOMY_REQUEST:
            new_form = new RobotomyRequestForm(f_name, target);
            std::cout << "Intern creates " << f_name << std::endl;
            break;
        case SHRUBBERY_CREATION:
            new_form = new ShrubberyCreationForm(f_name, target);
            std::cout << "Intern creates " << f_name << std::endl;
            break;
        case PRESIDENTIAL_PARDON:
            new_form = new PresidentialPardonForm(f_name, target);
            std::cout << "Intern creates " << f_name << std::endl;
            break;
        default:
            throw Intern::BadFormNameException();
    }
	return (new_form);
}

const char *Intern::BadFormNameException::what() const throw()
{
	return ("BadFormNameException : the Intern cannot create the form");
}