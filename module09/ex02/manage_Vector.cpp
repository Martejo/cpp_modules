#include "PmergeMe.hpp"


// Fonction pour afficher un vecteur
void printVector(const std::vector<unsigned int>& vec) {
    for (std::vector<unsigned int>::const_iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

// Fonction pour calculer les nombres de Jacobsthal
std::vector<unsigned int> generateJacobsthalVector(unsigned int n) {
    std::vector<unsigned int> jacobsthal;
    unsigned int a = 0, b = 1;
    std::size_t i = 0;
    while (i < n) {
        jacobsthal.push_back(a);
        unsigned int next = a * 2 + b;
        a = b;
        b = next;
        i++;
    }
    // printVector(jacobsthal);//test
    return jacobsthal;
}



// Fonction principale pour effectuer le tri Ford-Johnson
void fordJohnsonSort(std::vector<unsigned int>& arr) {
    if (arr.size() <= 1) return; //throw eexception si = 0 ?

    bool isOdd = arr.size() % 2 != 0;
    unsigned int laggard = 0;

    //si le vec contient un nombre impair d'elem
    if (isOdd) {
        laggard = arr.back(); //on conserve l' iterateur du dernier elem du vec
        arr.pop_back(); //on retire cet elem du vec
    }

    //on cree un vec qui contient les elem de l' ancien vec sous forme de paires
    std::vector<std::pair<unsigned int, unsigned int> > pairs;
    for (size_t i = 0; i < arr.size(); i += 2) {
        //on cree des paires triees 2 par 2
        pairs.push_back(std::make_pair(std::min(arr[i], arr[i + 1]), std::max(arr[i], arr[i + 1])));
    }

    //on ajoute la valeur max de chaque paire dans un nouveau vecteur S que l'on va trier
    std::vector<unsigned int> S;
    for (std::vector<std::pair<unsigned int, unsigned int> >::iterator it = pairs.begin(); it != pairs.end(); ++it) {
        S.push_back(it->second);
    }
    std::sort(S.begin(), S.end());

    //on ajoute la valeur min de chaque paire dans un nouveau vecteur 'pend' que l'on ne trie pas
    std::vector<unsigned int> pend;
    for (std::vector<std::pair<unsigned int, unsigned int> >::iterator it = pairs.begin(); it != pairs.end(); ++it) {
        pend.push_back(it->first);
    }

    //la sequence de Jacobsthal nous donne un vecteur contenant les index des elements du vecteur 'pend' que l'on devra inserer dans 'S'  
    std::vector<unsigned int> jacobsthalSeq = generateJacobsthalVector(pend.size());

    for (int i = pend.size() - 1; i >= 0; --i) {
            std::vector<unsigned int>::iterator it = std::lower_bound(S.begin(), S.end(), pend[i]);
            S.insert(it, pend[i]);
        }

    //on reinsere l'elem que l' on avait retire au debut de l' algo si le vecteur initial etait impair
    if (isOdd) {
        std::vector<unsigned int>::iterator it = std::lower_bound(S.begin(), S.end(), laggard);
        S.insert(it, laggard);
    }

    //arr = vecteur non trie passe par ref, on utilise l' operateur d' assignation pour lui affecter le contenu du vecteur S qui contient les memes valeurs mais triees par l' algo
    arr = S;
}