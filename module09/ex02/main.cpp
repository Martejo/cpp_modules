#include "PmergeMe.hpp"

// Fonction pour vérifier si la chaîne d'entrée est un unsigned int valide
bool isValidUnsignedInt(const std::string& str) {
    if (str.empty() || (!isdigit(str[0]) && str[0] != '+')) return false;
    for (size_t i = 0; i < str.size(); ++i) {
        if (!isdigit(str[i])) return false;
    }
    return true;
}


unsigned int    getInputArgs(char *arg)
{
    if (!isValidUnsignedInt(arg)) {
        std::cerr << "Error: Invalid input '" << arg << "'. Negative numbers are not allowed." << std::endl;
        throw (std::exception());
    }
    unsigned long ulValue = std::strtoul(arg, NULL, 10);
    if (ulValue > UINT_MAX) {
        std::cerr << "Error: Input '" << arg << "' is out of range for unsigned int." << std::endl;
        throw (std::exception());
    }
    return (static_cast<unsigned int>(ulValue));
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Error: Please provide at least one number as argument." << std::endl;
        return 1;
    }


    //ECRITURE DE BEFORE ET AFTER SANS PRISE EN COMPTE DU TEMPS
    {
        std::vector<unsigned int> vContainer;
        unsigned int value;
        for (int i = 1; i < argc; ++i) {
            try{
                value = getInputArgs(argv[i]);
            }catch(std::exception & e){ 
                std::cerr << "Error" << std::endl;
            }
            vContainer.push_back(static_cast<unsigned int>(value));
        }
        std::cout << "Before: ";
        printVector(vContainer);

        fordJohnsonSort(vContainer);

        std::cout << "After: ";
        printVector(vContainer);
    }


    //TIME VECTOR
    /*
        Plus rapide pour cette operation car l'acces aux valeurs internes est optimise dans std::vector ce qui dans notre cas est important
        On peut d'ailleurs utiliser l'operateur[] pour acceder aux index
    */
    {
        clock_t vStart = clock();
        std::vector<unsigned int> vContainer;
        for (int i = 1; i < argc; ++i) {
            if (!isValidUnsignedInt(argv[i])) {
                std::cerr << "Error: Invalid input '" << argv[i] << "'. Negative numbers are not allowed." << std::endl;
                return 1;
            }
            unsigned long ulValue = std::strtoul(argv[i], NULL, 10);
            if (ulValue > UINT_MAX) {
                std::cerr << "Error: Input '" << argv[i] << "' is out of range for unsigned int." << std::endl;
                return 1;
            }
            vContainer.push_back(static_cast<unsigned int>(ulValue));
        }

        fordJohnsonSort(vContainer);
        clock_t vEnd = clock();
        double vDuration = static_cast<double>(vEnd - vStart) / CLOCKS_PER_SEC * 1e6;

        std::cout << "Time to process a range of " << vContainer.size() << " elements with std::vector : " << vDuration << " us" << std::endl;
    }
    

    //UTILISATION DE LA LISTE
    /* 
        Plus long pour cette operation car l'acces aux valeurs internes est plus long que pour std::vector ce qui dans notre cas est important
        On ne peut d' ailleurs pas utiliser l' operateur[] et on est obliges de passer par des iterateurs
    */
    {
        clock_t lStart = clock();
        std::list<unsigned int> lContainer;
        for (int i = 1; i < argc; ++i) {
            if (!isValidUnsignedInt(argv[i])) {
                std::cerr << "Error: Invalid input '" << argv[i] << "'. Negative numbers are not allowed." << std::endl;
                return 1;
            }
            unsigned long ulValue = std::strtoul(argv[i], NULL, 10);
            if (ulValue > UINT_MAX) {
                std::cerr << "Error: Input '" << argv[i] << "' is out of range for unsigned int." << std::endl;
                return 1;
            }
            lContainer.push_back(static_cast<unsigned int>(ulValue));
        }
        fordJohnsonSort(lContainer);
        clock_t lEnd = clock();
        double lDuration = static_cast<double>(lEnd - lStart) / CLOCKS_PER_SEC * 1000000;
        std::cout << "Time to process a range of " << lContainer.size() << " elements with std::list : " << lDuration << " us" << std::endl;
    }

    return 0;
}