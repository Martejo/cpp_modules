#include "header.hpp"

PhoneBook::PhoneBook()
{

}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::welcome(void) const
{
	std::cout << std::endl;
	std::cout << "Welcome to the phonebook app !" << std::endl;
	std::cout << std::endl;
	std::cout << "------------HOW TO USE------------" << std::endl;
	std::cout << "ADD\t: To add a contact." << std::endl;
	std::cout << "SEARCH\t: To search for a contact." << std::endl;
	std::cout << "EXIT\t: to quite the PhoneBook." << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << std::endl;
}

void	PhoneBook::displayPhoneBook(void) const
{
	std::cout << "-----PHONEBOOK CONTACTS-----" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		if (this->_contacts[i].isInitContact())
			this->_contacts[i].viewContacts(i);
	}
	std::cout << std::endl;
}

int	PhoneBook::_searchInput(void) const
{
	int		index;
	bool	valid;

	index = -1;
	valid = false;
	do
	{
		std::cout << "Please enter the contact index: " << std::flush;
		std::cin >> index;
		if (std::cin.good() && (index >= 0 && index < 8))
			valid = true;
		else
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			std::cout << "Invalid index. Please try again." << std::endl;
		}
	} while (!valid);
	return (index);
}

void	PhoneBook::searchContact(void) const
{
	int	i;

	i = this->_searchInput();
	this->_contacts[i].printContact(i);
}

void	PhoneBook::addContact(void)
{
	static int	contactIndex;

	if (contactIndex == 8)
		contactIndex = 0;
	this->_contacts[contactIndex].initContact();
	contactIndex++;
}