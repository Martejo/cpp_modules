#include "PmergeMe.hpp"
#include <sys/time.h>

template <typename Container>
bool isSorted(const Container& data) {
    typename Container::const_iterator it = data.begin();
    if (it == data.end())
        return true; // Conteneur vide est considéré comme trié
    typename Container::const_iterator next_it = it;
    ++next_it;
    while (next_it != data.end()) {
        if (*next_it < *it)
            return false; // Trouvé un élément hors de l'ordre
        ++it;
        ++next_it;
    }
    return true; // Le conteneur est trié
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cerr << "Erreur: veuillez fournir une séquence d'entiers positifs en arguments." << std::endl;
        return 1;
    }

    // Récupération des entiers depuis les arguments
    std::vector<int> dataVector;
    std::deque<int> dataDeque;
    for (int i = 1; i < argc; ++i)
    {
        std::string arg = argv[i];
        for (size_t j = 0; j < arg.length(); ++j)
        {
            if (!isdigit(arg[j]))
            {
                std::cerr << "Erreur: tous les arguments doivent être des entiers positifs." << std::endl;
                return 1;
            }
        }
        int value = std::atoi(argv[i]);
        if (value < 0)
        {
            std::cerr << "Erreur: tous les arguments doivent être des entiers positifs." << std::endl;
            return 1;
        }
        dataVector.push_back(value);
        dataDeque.push_back(value);
    }

    // Affichage de la séquence non triée
    std::cout << "Before: ";
    for (size_t i = 0; i < dataVector.size(); ++i)
    {
        std::cout << dataVector[i] << " ";
    }
    std::cout << std::endl;

    // Tri avec std::vector
    PmergeMe sorter;

    clock_t vStart = clock();
    sorter.sortVector(dataVector);
    clock_t vEnd = clock();
	double vDuration = (static_cast<double>(vEnd) - static_cast<double>(vStart)) / static_cast<double>(CLOCKS_PER_SEC) * 1000.0;
	std::cout << "Time to process a range of " << dataVector.size() << " elements with std::vector : " << vDuration << " ms" << std::endl;


    // Tri avec std::deque
    clock_t dStart = clock();
    sorter.sortDeque(dataDeque);
    clock_t dEnd = clock();
	double dDuration = (static_cast<double>(dEnd) - static_cast<double>(dStart)) / static_cast<double>(CLOCKS_PER_SEC) * 1000.0;
    std::cout << "Time to process a range of " << dataDeque.size() << " elements with std::deque  : " << dDuration << " ms" << std::endl;


    // Affichage de la séquence triée
    std::cout << "After: ";
    for (size_t i = 0; i < dataVector.size(); ++i)
    {
        std::cout << dataVector[i] << " ";
    }
    std::cout << std::endl;

    // Vérification si le vecteur est trié
    if (isSorted(dataVector)) {
        std::cout << "Le vecteur est bien trié." << std::endl;
    } else {
        std::cout << "Le vecteur n'est pas trié." << std::endl;
    }

    return 0;
}
