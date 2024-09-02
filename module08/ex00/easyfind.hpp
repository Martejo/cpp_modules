#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <algorithm>


/*
	T represente la variable du template
	typename T represente le type de la variable du template
	typename T::iterator represente le type iterator qui est utilise dans le container de type T (T  est donc obligatoirement un container contenant un type iterator)

	Explication de la syntaxe "typename T::iterator"
	Types dépendants : Dans les templates, des membres comme T::iterator sont des types qui dépendent du type T. Le compilateur ne peut pas savoir automatiquement que T::iterator est un type, d'où l'erreur.
	Usage de typename : En C++, le mot-clé typename est utilisé pour indiquer au compilateur que ce qui suit est un type dépendant du template.
*/


template <typename T>
typename T::iterator easyfind(T& container, int value)
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if(it == container.end())
		throw(std::runtime_error("Exception: Value not found"));
	return(it);
}

#endif