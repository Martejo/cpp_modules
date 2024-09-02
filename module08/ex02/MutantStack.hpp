#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP


#include <string>
#include <iostream>
#include <exception>
#include <algorithm>
#include <stack>
#include <deque>


/*
Le mot-clé typename est utilisé ici pour indiquer que iterator est un type dépendant d'un paramètre de template 
(T dans ce cas). En C++, lorsque vous accédez à un type à l'intérieur d'une classe template, 
vous devez spécifier typename pour indiquer au compilateur qu'il s'agit d'un type
*/


/*
1. Faciliter l'accès aux types associés au conteneur sous-jacent :
La classe MutantStack est basée sur std::stack, qui utilise un conteneur sous-jacent pour stocker les éléments 
(par défaut, un std::deque). Chaque conteneur de la STL (comme std::deque, std::vector, etc.) 
a des types internes associés, comme iterator, const_iterator, size_type, etc.

En définissant cette ligne au sein de la classe, tu crées un alias de type (iterator) qui est directement accessible depuis la classe MutantStack. Cela simplifie la manière d'utiliser les itérateurs pour interagir avec les éléments de la pile.

2. Rendre l'interface de la classe plus intuitive :
En définissant un alias pour l'itérateur au sein de la classe, 
tu rends l'utilisation de ta classe plus intuitive pour les autres développeurs (ou pour toi-même plus tard). 
Les utilisateurs de MutantStack peuvent simplement écrire MutantStack<int>::iterator pour déclarer un itérateur sur une pile d'entiers, plutôt que d'avoir à connaître et à manipuler les détails internes comme std::deque<int>::iterator
*/

/*
Puisque std::stack gère déjà l'opérateur =, 
et que ta classe MutantStack ne semble pas nécessiter de gestion particulière pour ce qui est des ressources, 
il n'est pas nécessaire de surcharger cet opérateur dans ta classe. 
Tu peux simplement utiliser l'opérateur hérité tel quel.
Cependant si on souhaite le faire, on peut passer par un appel de l'opérateur d'affectation de la classe de base
*/

template<typename T>


class MutantStack: public std::stack<T, std::deque<T> >
{

	public:
		typedef std::stack<T, std::deque<T> > stackClass; //alias pour la classe stack
		typedef typename std::deque<T>::iterator iterator; //alias pour l'iterator (pratique pour appeler l' iterateur depuis l' exterieur (attention, le typedef doit etre public))
		
		MutantStack() : stackClass(){};
		MutantStack(const MutantStack<T>& other) : stackClass(other) {};
		~MutantStack(){};

		MutantStack<T>&		operator=(const MutantStack<T>& other) {
        if (this != &other) { 
            stackClass::operator=(other); // Appel de l'opérateur d'affectation de la classe de base
        }
        return *this;
    }

	//on accede a la variable c qui est en fait le container std::deque qui est contenu dans la stack et qui du coup contient en son sein les methodes begin() et end()
	iterator begin(){return this->c.begin();};
	iterator end(){return this->c.end();};
};



#endif