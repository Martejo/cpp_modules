#include "header.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

std::string	Contact::_getUserInput(std::string str) const
{
	std::string	input = "";
	bool		validInput = false;

	do
	{
		std::cout << str << std::flush;
		std::getline(std::cin, input);
		if (std::cin.good() && !input.empty())
			validInput = true;
		else
		{
			std::cin.clear();
			std::cout << "Invalid input; please try again." << std::endl;
		}
	} while (!validInput);
	return (input);
}

std::string	Contact::_trimeContact(std::string content) const
{
	if (content.length() > 10)
		return (content.substr(0, 9) + ".");
	return (content);
}

void	Contact::initContact(void)
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	this-> _firstName = this->_getUserInput("Please enter you first name: ");
	this->_lastName = this->_getUserInput("Please enter your last name: ");
	this->_nickName = this->_getUserInput("Please enter your nickname: ");
	this->_phoneNumber = this->_getUserInput("Please enter your phone number: ");
	this->_darkestSecret = this->_getUserInput("Please enter your darkest secret: ");
	 std::cout << std::endl;
}

void	Contact::viewContacts(int index) const
{
	if (this->_firstName.empty() || this->_lastName.empty() || this->_nickName.empty())
		return ;
	std::cout << "|" << std::setw(10) << index << std::flush;
	std::cout << "|" << std::setw(10) << this->_trimeContact(this->_firstName) << std::flush;
	std::cout << "|" << std::setw(10) << this->_trimeContact(this->_lastName) << std::flush;
	std::cout << "|" << std::setw(10) << this->_trimeContact(this->_nickName) << std::flush;
	std::cout << "|" << std::endl;
}

void	Contact::printContact(int index) const
{
	if (this->_firstName.empty() || this->_lastName.empty() || this->_nickName.empty())
		return ;
	std::cout << std::endl;
	std::cout << "Contact: " << index << std::endl;
	std::cout << "Fistname\t" << this->_firstName << std::endl;
	std::cout << "lastname\t" << this->_lastName << std::endl;
	std::cout << "Nickname\t" << this->_nickName << std::endl;
	std::cout << std::endl;
}
