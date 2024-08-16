#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <cmath>
#include <cerrno> 
#include <cctype>  // Pour std::isprint

/*
Differentes manieres de creer une classe non-instanciable

**Constructeur privé : Empêche la création d'instances depuis l'extérieur de la classe.
Constructeur = delete : Supprime explicitement les constructeurs pour empêcher l'instanciation.
Classe abstraite : Utilise des méthodes pures virtuelles pour créer une classe que vous ne pouvez pas instancier directement.


Utiliser une methode contenue dans une classe non-instanciable (Constructeur prive)

**Méthodes statiques : Utilisez-les si vous n'avez pas besoin d'instances de la classe.
xMéthodes amies : Permettent à des fonctions ou classes spécifiques d'accéder aux membres privés.
xFonctions globales ou membres statiques : Encapsulent la logique d'utilisation des méthodes privées.
xPattern Singleton : Garantit qu'il n'y a qu'une seule instance de la classe et fournit un point d'accès global à cette instance.

Une méthode statique dans une classe en C++ est une méthode qui est associée à la classe elle-même plutôt qu'à une instance spécifique de cette classe. 
Cela signifie que vous pouvez appeler une méthode statique sans avoir besoin de créer une instance de la classe.

*/



class ScalarConverter {
	public:
		static void convert(const std::string &literal);

		class OverflowException: public std::exception {
			public:
				const char *what() const throw(); 
		};
		
		class ImpossibleConversionException: public std::exception {
			public:
				const char *what() const throw(); 
		};


	private:
		ScalarConverter();
		static void detectImpossibleConversion(const std::string &literal);
		static void detectOverflow(const std::string &literal);

		static bool charDetected(const std::string &literal);
		static void convertToInt(const std::string &literal);
		static void convertToFloat(const std::string &literal);
		static void convertToDouble(const std::string &literal);
		static void convertToChar(const std::string &literal);

		static int choosePrecision(const std::string &literal);
		static std::string strToLower(const std::string &literal);

};