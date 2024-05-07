/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemartel <gemartel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:16:33 by gemartel          #+#    #+#             */
/*   Updated: 2024/05/06 16:10:23 by gemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"


# define BLUE "\033[1m\033[4m\033[34m"
# define RESET "\033[0m"
int main()
{
	{
		std::cout << BLUE << "\nCreating a spell book.\n" << RESET << std::endl;
		IMateriaSource* src = new MateriaSource();
		
		std::cout << BLUE << "\nCreating a character.\n" << RESET << std::endl;
		ICharacter* me = new Character("Noct");
		ICharacter* bob = new Character("Pablo");

		std::cout << BLUE << "\nAdding the spell to the book.\n" << RESET << std::endl;
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		std::cout << BLUE << "\nTranscription of spell into spell parchment.\n" << RESET << std::endl;
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		std::cout << BLUE << "\nNoct uses spells on Pablo\n" << RESET << std::endl;
		
		me->use(0, *bob);
		me->use(1, *bob);

		std::cout << BLUE << "\nPablo takes revenge on noct\n" << RESET << std::endl;
		tmp = src->createMateria("ice");
		bob->equip(tmp);
		bob->use(0, *me);

		std::cout << BLUE << "\nNoct changes its spell\n" << RESET << std::endl;
		Character *test = dynamic_cast<Character*>(me);
		tmp = test->getMateria(1);
		me->unequip(1);
		me->equip(NULL);
		me->equip(src->createMateria("ice"));
		me->use(1, *bob);

		std::cout << BLUE << "\nDestroying instances\n" << RESET << std::endl;
		delete tmp;
		std::cout << std::endl;
		delete src;
		std::cout << std::endl;
		delete bob;
		std::cout << std::endl;
		delete me;
	}

	return 0;
}
