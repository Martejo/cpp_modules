#include "Span.hpp"
#include <iostream>

#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include "Span.hpp"

int main() {
    try {
        std::cout << "--------Test 1: Création de Span et ajout d'un seul nombre a la fois------" << std::endl;
        Span span(10);  // Capacité de 5 éléments
        span.addNumber(10);
        span.addNumber(20);
        span.addNumber(30);

        std::cout << "Span elements: " << span;




        std::cout << "\n\n--------Test 2: Ajout d'une range d'itérateurs ------" << std::endl;
		// Créer un std::vector vide
		std::vector<int> numbers;

		// Ajouter des éléments au vecteur
		numbers.push_back(40);
		numbers.push_back(50);
		numbers.push_back(60);
		numbers.push_back(70);
		numbers.push_back(80);
		try{
        	span.addItRange(numbers.begin(), numbers.end(), numbers);
		}
		catch (const Span::MaxSizeExeption& e) {
            std::cerr << e.what();
        }

        // Afficher les éléments dans Span
        std::cout << "Span elements: " << span;




        std::cout << "\n\n--------Test 3: Calculer les intervalles ------" << std::endl;
        std::cout << "Shortest Span: " << span.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << span.longestSpan() << std::endl;




        std::cout << "\n\n--------Test 4: Gestion de l'exception pour dépassement de taille ------" << std::endl;
        Span spanSmall(3);  // Capacité de 3 éléments
        spanSmall.addNumber(1);
        spanSmall.addNumber(2);
        spanSmall.addNumber(3);

        // Cette ligne devrait lancer une exception car la capacité est atteinte
        try {
            spanSmall.addNumber(4);
        } catch (const Span::MaxSizeExeption& e) {
            std::cerr << e.what();
        }





        std::cout << "\n\n--------Test 5: Gestion des exceptions pour les opérations avec des itérateurs invalides ------" << std::endl;
		// Créer un std::vector vide
		std::vector<int> invalidNumbers;

		// Ajouter des éléments au vecteur
		invalidNumbers.push_back(100);
		invalidNumbers.push_back(200);
		invalidNumbers.push_back(300);
        Span spanWithException(2);  // Capacité de 2 éléments

        try {
            // Cette ligne devrait lancer une exception car les itérateurs ne sont pas valides
            spanWithException.addItRange(invalidNumbers.begin(), invalidNumbers.end(), numbers);
        } catch (const std::invalid_argument& e) {
            std::cerr << e.what();
        }

        std::cout << "\n\n--------Test 6: Gestion des exceptions pour le calcul des intervalles avec trop peu d'éléments ------" << std::endl;
        Span spanEmpty(1);  // Capacité de 1 élément
        try {
            std::cout << spanEmpty.shortestSpan() << std::endl;
        } catch (const Span::SpanExeption& e) {
            std::cerr << e.what();
        }

    } catch (const std::exception& e) {
        std::cerr << "Unhandled exception: " << e.what() << std::endl;
    }

    return 0;
}