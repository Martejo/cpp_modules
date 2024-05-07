/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemartel <gemartel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:21:02 by gemartel          #+#    #+#             */
/*   Updated: 2024/05/06 11:21:04 by gemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>

class AAnimal
{
protected:
	std::string	type;
public:
	AAnimal();
	AAnimal(std::string type);
	AAnimal( AAnimal &copy );
	virtual ~AAnimal();
	AAnimal	&operator=( AAnimal &a);

	virtual void	makeSound() const = 0;
	virtual std::string getType() const;
};

#endif