/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemartel <gemartel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 09:58:31 by gemartel          #+#    #+#             */
/*   Updated: 2024/04/19 14:35:08 by gemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>  // Pour std::ifstream
#include <iostream> // Pour std::cerr
#include <sstream>  // Pour std::stringstream
#include <string>   // Pour std::string


std::string const ft_sed(std::string const &buffer, std::string const &from, std::string const &to)
{
	std::string newStr;
	std::size_t      pos = 0;
	std::size_t      last = 0;

	//pour eviter que la taille de std::string newStr soit sans cesse reallouee
	//on lui indique une taille initiale proche de la taille finale
	newStr.reserve(buffer.length());

	//avancer dans buffer jusqu'a ce qu' on ne trouve plus aucune occurence de from
	while((pos = buffer.find(from, last)) != std::string::npos)
	{
		//on ajoute la sub situee avant l'occurence de from detectee par find()
		newStr.append(buffer, last, (pos - last));
		//on ajoute la nouvelle sub
		newStr.append(to);
		//on avance dans le buffer pour ignorer les chars de from
		last = pos + from.length();
	}
	//on ajoute la sub finale (copie de last jusqu'a la fin de buffer)
	newStr.append(buffer.substr(last));
	return (newStr);
}

int main(int ac, char *av[]) 
{
	if (ac != 4)
	{
		std::cerr << "wrong number of arguments" << std::endl;
		std::cerr << "usage : <file> <old_word> <new_word>" << std::endl;
		return (1);
	}

	// Ouvrir le fichier en mode lecture
	std::ifstream infile(av[1]);
	if (!infile.is_open())
	{
		std::cout << "Error: " << av[1] << ":" 
		<< " infile can't be opened" << std::endl;
		return (1);
	}

	std::string newFileName = std::string(av[1]) + ".replace";

	//Creer et Ouvrir le fichier en mode ecriture
	//c_str renvoie un ptr de type const char requis par ofstream
	std::ofstream outfile(newFileName.c_str());
	if (!outfile.is_open())
	{
		std::cout << "Error: " << newFileName << ":" 
		<< " outfile can't be opened or created" << std::endl;
		return (1);
	}

	std::string line;
	while (std::getline(infile, line))
		outfile << ft_sed(line, av[2], av[3]) << std::endl;
	
	infile.close();
	outfile.close();
	return (0);
}