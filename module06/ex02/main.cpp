#include <iostream>
#include <cstdlib>
#include <exception>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

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
}

/*
	le dynamic_cast d'une référence (plutôt que d'un pointeur) peut lever une exception si le cast échoue
	(void)ptr sert a rm les alertes de compilation
*/
void identify(Base& p)
{
	try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A identified" << std::endl;
    }
    catch (const std::exception&) {}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B identified" << std::endl;
    }
    catch (const std::exception&) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C identified" << std::endl;
    }
    catch (const std::exception&) {}
}


int main()
{
	Base *ptr;

	for (int i = 0; i < 5; i++)
	{
        std::cout << "\n\n --------------- TEST "<< i + 1 << " --------------" << std::endl;
		ptr = generate();
		std::cout << "find class type by pointer => ";
		identify(ptr);
		std::cout << "find class type by reference => ";
		identify(*ptr);
		delete ptr;
	}
	return(0);
}