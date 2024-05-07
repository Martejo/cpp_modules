/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemartel <gemartel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:12:18 by gemartel          #+#    #+#             */
/*   Updated: 2024/05/06 11:18:47 by gemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat: public AAnimal
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