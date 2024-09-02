#include <iostream>
#include <cstdlib>
#include <exception>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

// Codes ANSI pour les couleurs
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"


/*
dynamic_cast est un opérateur de conversion de type utilisé principalement pour le cast (conversion de type) 
en temps d'exécution, surtout dans le contexte des hiérarchies de classes polymorphes.

**Conversion de type sécurisée en temps d'exécution : 
Contrairement aux cast statiques (static_cast), 
dynamic_cast vérifie à l'exécution si la conversion est valide. 
Il est donc principalement utilisé pour des conversions entre types liés par héritage.

**Hiérarchies de classes polymorphes : 
dynamic_cast est utile pour les classes qui utilisent le polymorphisme, 
c'est-à-dire les classes qui ont au moins une fonction virtuelle (typiquement une classe de base avec des méthodes virtuelles). Cela permet de déterminer à l'exécution le type réel de l'objet auquel un pointeur ou une référence de base pointe.

**Conversion en pointeur : Lorsque dynamic_cast est utilisé pour convertir un pointeur, 
il renvoie un pointeur du type cible si la conversion est valide, sinon il renvoie un pointeur nul (nullptr).

**Conversion en référence : 
Lorsque dynamic_cast est utilisé pour convertir une référence, 
il lance une exception de type std::bad_cast si la conversion n'est pas valide. C'est donc plus sûr pour détecter les erreurs par rapport aux conversions en pointeur qui pourraient simplement renvoyer nullptr.
*/

Base *generate(void)
{
	static unsigned int nb_call = 0;
	if (nb_call > 20)
		nb_call = 0;
	nb_call++;

	srand((unsigned) time(NULL) * nb_call);
	int					rand_value = std::rand() % 3;

	switch (rand_value)
	{
		case 0:
			std::cout << "A is generated :" << std::endl;
			return (new A);
			break ;
		case 1:
			std::cout << "B is generated :" << std::endl;
			return (new B);
			break ;	
		default :
			std::cout << "C is generated :" << std::endl;
			return (new C);
			break ;
	}
}

void identify(Base* p)
{
	if(dynamic_cast<A*>(p))
		std::cout << "A identified" << std::endl;

	else if(dynamic_cast<B*>(p))
		std::cout << "B identified" << std::endl;

	else if(dynamic_cast<C*>(p))
		std::cout << "C identified" << std::endl;
	else 
		std::cout << "Unkniwn type" << std::endl;
}

/*
	le dynamic_cast d'une référence (plutôt que d'un pointeur) peut lever une exception si le cast échoue
	(void)ptr sert a rm les alertes de compilation
*/


void identify(Base& p)
{
    if (dynamic_cast<A*>(&p)) {
        std::cout << "A identified" << std::endl;
    } else if (dynamic_cast<B*>(&p)) {
        std::cout << "B identified" << std::endl;
    } else if (dynamic_cast<C*>(&p)) {
        std::cout << "C identified" << std::endl;
    } else {
        std::cout << "Unknown type" << std::endl;
    }
}


void printHeader(int testNumber) {
    std::cout << CYAN << "\n\n --------------- TEST " << testNumber << " --------------" << RESET << std::endl;
}

void printIdentificationResult(const std::string& method, const std::string& type) {
    std::cout << YELLOW << method << " => " << GREEN << type << RESET << std::endl;
}

int main() {
    Base *ptr;

    for (int i = 0; i < 5; i++) {
        printHeader(i + 1);

        ptr = generate();

        std::cout << BLUE << "Identifying class type by pointer: " << RESET;
        identify(ptr);

        std::cout << BLUE << "Identifying class type by reference: " << RESET;
        identify(*ptr);

        delete ptr;
    }

	 // Test supplémentaire : identification d'un pointeur nul
    printHeader(6);
    std::cout << RED << "Testing with nullptr" << RESET << std::endl;

    ptr = NULL;

    try {
        std::cout << BLUE << "Identifying class type by pointer: " << RESET;
        identify(ptr);  // Ce test devrait échouer ou afficher un résultat spécifique
    } catch (...) {
        std::cout << RED << "Exception caught while identifying a nullptr" << RESET << std::endl;
    }

    try {
        std::cout << BLUE << "Identifying class type by reference: " << RESET;
        identify(*ptr);  // Ce test lancera une exception car on déréférence un pointeur nul
    } catch (...) {
        std::cout << RED << "Exception caught while identifying a nullptr reference" << RESET << std::endl;
    }

    return 0;
}