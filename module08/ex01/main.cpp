#include "Span.hpp"
#include <list>
#include <deque>

// Codes ANSI pour les couleurs
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

int main()
{
    try {
        std::cout << CYAN << "--------Test 1: Création de Span et ajout d'un seul nombre a la fois------" << RESET << std::endl;
        Span span(10);  // Capacité de 10 éléments
        span.addNumber(10);
        span.addNumber(20);
        span.addNumber(30);

        std::cout << "Span elements: " << span;

/*********************************/

        std::cout << CYAN << "\n\n--------Test 2: Ajout d'une range d'itérateurs ------" << RESET <<  std::endl;
		// Créer un std::vector avec des éléments
		std::vector<int> numbers;
		numbers.push_back(40);
		numbers.push_back(50);
		numbers.push_back(60);
		numbers.push_back(70);
		numbers.push_back(80);
		try{
        	span.addItRange(numbers.begin(), numbers.end());
		}
		catch (const Span::MaxSizeException& e) {
            std::cerr << e.what();
        }

        // Afficher les éléments dans Span
        std::cout << "Span elements: " << span;

/**********************************/

        std::cout << CYAN << "\n\n--------Test 3: Calculer les intervalles ------" << RESET << std::endl;

        std::cout << "Shortest Span: " << span.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << span.longestSpan() << std::endl;

/*********************************/

        std::cout << CYAN << "\n--------Test 4: Gestion de l'exception pour dépassement de taille ------" << RESET << std::endl;
        Span spanSmall(3);  // Capacité de 3 éléments
        spanSmall.addNumber(1);
        spanSmall.addNumber(2);
        spanSmall.addNumber(3);

        // Cette ligne devrait lancer une exception car la capacité est atteinte
        try {
            spanSmall.addNumber(4);
        } catch (const Span::MaxSizeException& e) {
            std::cerr << e.what();
        }



        std::cout << CYAN << "\n\n--------Test 5: Gestion des exceptions pour les opérations avec des itérateurs invalides ------" << RESET << std::endl;
		// Créer un std::vector avec des éléments
		std::vector<int> invalidNumbers;
		invalidNumbers.push_back(100);
		invalidNumbers.push_back(200);
		invalidNumbers.push_back(300);
        Span spanWithException(2);  // Capacité de 2 éléments

        try {
            // Cette ligne devrait lancer une exception car on essaie d'ajouter 3 éléments dans un Span de capacité 2
            spanWithException.addItRange(invalidNumbers.begin(), invalidNumbers.end());
        } catch (const Span::MaxSizeException& e) {
            std::cerr << e.what();
        }

        std::cout << CYAN << "\n\n--------Test 6: Gestion des exceptions pour le calcul des intervalles avec trop peu d'éléments ------" << RESET << std::endl;
        Span spanEmpty(1);  // Capacité de 1 élément
        spanEmpty.addNumber(42);
        try {
            std::cout << spanEmpty.shortestSpan() << std::endl;
        } catch (const Span::SpanException& e) {
            std::cerr << e.what();
        }

        std::cout << CYAN << "\n\n--------Test 7: Ajout et test avec 10 000 nombres ------" << RESET <<  std::endl;
        Span largeSpan(10000);
        std::vector<int> largeNumbers;
        for(int i = 0; i < 10000; ++i) {
            largeNumbers.push_back(i);
        }
        try{
            largeSpan.addItRange(largeNumbers.begin(), largeNumbers.end());
        }
        catch (const Span::MaxSizeException& e) {
            std::cerr << e.what();
        }
        std::cout << "Shortest Span (largeSpan): " << largeSpan.shortestSpan() << std::endl;
        std::cout << "Longest Span (largeSpan): " << largeSpan.longestSpan() << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Unhandled exception: " << e.what() << std::endl;
    }

    /*********************/
        std::cout << CYAN << "\n\n--------Test 8: Ajout avec des itérateurs de std::list<int> ------" << RESET << std::endl;
        Span listSpan(15);
        std::list<int> listNumbers;
        for(int i = 1000; i < 1005; ++i) {
            listNumbers.push_back(i);
        }
        try{
            listSpan.addItRange(listNumbers.begin(), listNumbers.end());
        }
        catch (const Span::MaxSizeException& e) {
            std::cerr << e.what();
        }
        std::cout << "ListSpan elements: " << listSpan;

        std::cout << "\nShortest Span (listSpan): " << listSpan.shortestSpan() << std::endl;
        std::cout << "Longest Span (listSpan): " << listSpan.longestSpan() << std::endl;

    return (0);
}
