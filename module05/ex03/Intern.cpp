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

AForm* Intern::createRobotomyRequestForm(const std::string& target) const
{
	return (new RobotomyRequestForm(target));
}

AForm* Intern::createShrubberyCreationForm(const std::string& target) const
{
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::createPresidentialPardonForm(const std::string& target) const
{
	return (new PresidentialPardonForm(target));
}

/*
 Tableau de pointeurs vers des fonctions membres
 Syntaxe : 
 <Type de retour> (<Classe>::*<Nom du pointur>[<Taille du tableau>])(<Paramètres>) const

 Exemple concret dans notre cas :
 AForm* (Intern::*formCreationMethods[3])(const std::string& target) const

 Explication :
 - `AForm*` : Type de retour de la fonction membre (un pointeur vers un objet de type AForm).
 - `Intern::` : La fonction membre appartient à la classe Intern.
 - `*formCreationMethods[3]` : Nom du tableau (formCreationMethods) qui contient 3 pointeurs.
 - `(const std::string& target) const` : Signature de la fonction membre, prenant un std::string en paramètre et étant const.
*/

AForm	*Intern::makeForm(const std::string f_name, const std::string target) const
{
	std::string formNames[3] = {"robotomy request", "shrubbery creation", "presidential pardon"};

	// Tableau de pointeurs de fonctions membres qui retournent un pointeur de AForm
	AForm* (Intern::*formCreationMethods[3])(const std::string& target) const = 
	{
		&Intern::createRobotomyRequestForm,
		&Intern::createShrubberyCreationForm,
		&Intern::createPresidentialPardonForm
	};

	for (int i = 0; i < 3; i++) {
		if (f_name == formNames[i]) {
			std::cout << "Intern creates " << formNames[i] << std::endl;
			return (this->*formCreationMethods[i])(target);
		}
	}

	throw Intern::BadFormNameException();
	return (NULL);
}

const char *Intern::BadFormNameException::what() const throw()
{
	return ("BadFormNameException : the Intern cannot create the form");
}