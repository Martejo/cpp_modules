#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <sstream>
#include <ctime>
#include <cstdlib>

class PmergeMe
{
public:
    PmergeMe();
    ~PmergeMe();

    void sortVector(std::vector<int> &data);
    void sortDeque(std::deque<int> &data);

private:
    // Fonctions pour le tri avec std::vector
    void fordJohnsonSortVector(std::vector<int> &data);
    void mergeInsertVector(std::vector<int> &mainSeq, std::vector<int> &pending);
    void insertVector(std::vector<int> &mainSeq, int value);
    void insertionSortVector(std::vector<int> &data);

    // Fonctions pour le tri avec std::deque
    void fordJohnsonSortDeque(std::deque<int> &data);
    void mergeInsertDeque(std::deque<int> &mainSeq, std::deque<int> &pending);
    void insertDeque(std::deque<int> &mainSeq, int value);
    void insertionSortDeque(std::deque<int> &data);

    // Génération de la séquence de Jacobsthal
    std::vector<int> generateJacobsthalSequence(int n);
};

#endif
