#ifndef CONTACT_HPP
# define CONTACT_HPP

#include "header.hpp"

class Contact
{
	private:
		std::string	_firstName;
		std::string _lastName;
		std::string _nickName;
		std::string _darkestSecret;
		std::string _phoneNumber;

		std::string _getUserInput(std::string str) const;
		std::string	_trimeContact(std::string content) const;
	public:
		Contact(); //Constructeur
		~Contact(); //Destructeur
		void	initContact(void);
		void	viewContacts(int index) const;
		void	printContact(int index) const;

};



#endif