/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemartel <gemartel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:12:18 by gemartel          #+#    #+#             */
/*   Updated: 2024/04/24 15:11:01 by gemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
	private:
		std::string _name;
		Brain	*_brain;
		
	public:
		Cat();
		Cat(std::string name);
		Cat(Cat const &copy);
		virtual ~Cat();
		Cat &operator=(Cat const &a);

		void makeSound() const;
};


#endif