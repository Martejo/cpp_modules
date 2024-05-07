/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemartel <gemartel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 09:58:47 by gemartel          #+#    #+#             */
/*   Updated: 2024/04/19 09:58:49 by gemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl
{
	public:
	void complain( std::string level );
	Harl(void);
	~Harl(void);

	private:
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
};

#endif