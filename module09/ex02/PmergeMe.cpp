#include "PmergeMe.hpp"

// Constructeur
PmergeMe::PmergeMe()
{
}

// Destructeur
PmergeMe::~PmergeMe()
{
}

// Génération de la séquence de Jacobsthal
std::vector<int> PmergeMe::generateJacobsthalSequence(int n)
{
    std::vector<int> sequence;
    sequence.push_back(1);
    if (n == 1)
        return sequence;
    sequence.push_back(3);
    int index = 2;
    while (true)
    {
        int nextValue = sequence[index - 1] + 2 * sequence[index - 2];
        if (nextValue > n)
            break;
        sequence.push_back(nextValue);
        index++;
    }
    return sequence;
}

// Tri par insertion pour std::vector
void PmergeMe::insertionSortVector(std::vector<int> &data)
{
    for (size_t i = 1; i < data.size(); ++i)
    {
        int key = data[i];
        size_t j = i;
        while (j > 0 && data[j - 1] > key)
        {
            data[j] = data[j - 1];
            --j;
        }
        data[j] = key;
    }
}

// Tri avec std::vector
void PmergeMe::sortVector(std::vector<int> &data)
{
    fordJohnsonSortVector(data);
}

void PmergeMe::fordJohnsonSortVector(std::vector<int> &data)
{
    if (data.size() <= 1)
        return;

    // Étape 1: Apparier et trier les paires
    std::vector<int> mainSeq;
    std::vector<int> pending;
    size_t i;
    for (i = 0; i + 1 < data.size(); i += 2)
    {
        int first = data[i];
        int second = data[i + 1];
        if (first > second)
            std::swap(first, second);
        mainSeq.push_back(second);
        pending.push_back(first);
    }
    // Si taille impaire, ajouter le dernier élément à mainSeq
    if (i < data.size())
    {
        mainSeq.push_back(data[i]);
    }

    // Étape 2: Trier mainSeq avec insertion sort
    insertionSortVector(mainSeq);

    // Étape 3: Insérer les éléments pendants en utilisant la séquence de Jacobsthal
    mergeInsertVector(mainSeq, pending);

    // Mise à jour des données triées
    data = mainSeq;
}

void PmergeMe::mergeInsertVector(std::vector<int> &mainSeq, std::vector<int> &pending)
{
    std::vector<int> jacobsthalSeq = generateJacobsthalSequence(pending.size());
    std::vector<bool> inserted(pending.size(), false);

    // Insertion selon la séquence de Jacobsthal
    for (size_t i = 0; i < jacobsthalSeq.size(); ++i)
    {
        int index = jacobsthalSeq[i] - 1;
        if (index >= 0 && index < (int)pending.size() && !inserted[index])
        {
            insertVector(mainSeq, pending[index]);
            inserted[index] = true;
        }
    }

    // Insertion des éléments restants
    for (size_t i = 0; i < pending.size(); ++i)
    {
        if (!inserted[i])
        {
            insertVector(mainSeq, pending[i]);
            inserted[i] = true;
        }
    }
}

void PmergeMe::insertVector(std::vector<int> &mainSeq, int value)
{
    // Recherche de la position d'insertion
    size_t left = 0;
    size_t right = mainSeq.size();
    while (left < right)
    {
        size_t mid = left + (right - left) / 2;
        if (mainSeq[mid] < value)
            left = mid + 1;
        else
            right = mid;
    }
    // Insertion à la position trouvée
    mainSeq.insert(mainSeq.begin() + left, value);
}

// Tri par insertion pour std::deque
void PmergeMe::insertionSortDeque(std::deque<int> &data)
{
    for (size_t i = 1; i < data.size(); ++i)
    {
        int key = data[i];
        size_t j = i;
        while (j > 0 && data[j - 1] > key)
        {
            data[j] = data[j - 1];
            --j;
        }
        data[j] = key;
    }
}

// Tri avec std::deque
void PmergeMe::sortDeque(std::deque<int> &data)
{
    fordJohnsonSortDeque(data);
}

void PmergeMe::fordJohnsonSortDeque(std::deque<int> &data)
{
    if (data.size() <= 1)
        return;

    // Étape 1: Apparier et trier les paires
    std::deque<int> mainSeq;
    std::deque<int> pending;
    size_t i;
    for (i = 0; i + 1 < data.size(); i += 2)
    {
        int first = data[i];
        int second = data[i + 1];
        if (first > second)
            std::swap(first, second);
        mainSeq.push_back(second);
        pending.push_back(first);
    }
    // Si taille impaire, ajouter le dernier élément à mainSeq
    if (i < data.size())
    {
        mainSeq.push_back(data[i]);
    }

    // Étape 2: Trier mainSeq avec insertion sort
    insertionSortDeque(mainSeq);

    // Étape 3: Insérer les éléments pendants en utilisant la séquence de Jacobsthal
    mergeInsertDeque(mainSeq, pending);

    // Mise à jour des données triées
    data = mainSeq;
}

void PmergeMe::mergeInsertDeque(std::deque<int> &mainSeq, std::deque<int> &pending)
{
    std::vector<int> jacobsthalSeq = generateJacobsthalSequence(pending.size());
    std::vector<bool> inserted(pending.size(), false);

    // Insertion selon la séquence de Jacobsthal
    for (size_t i = 0; i < jacobsthalSeq.size(); ++i)
    {
        int index = jacobsthalSeq[i] - 1;
        if (index >= 0 && index < (int)pending.size() && !inserted[index])
        {
            insertDeque(mainSeq, pending[index]);
            inserted[index] = true;
        }
    }

    // Insertion des éléments restants
    for (size_t i = 0; i < pending.size(); ++i)
    {
        if (!inserted[i])
        {
            insertDeque(mainSeq, pending[i]);
            inserted[i] = true;
        }
    }
}

void PmergeMe::insertDeque(std::deque<int> &mainSeq, int value)
{
    // Recherche de la position d'insertion
    size_t left = 0;
    size_t right = mainSeq.size();
    while (left < right)
    {
        size_t mid = left + (right - left) / 2;
        if (mainSeq[mid] < value)
            left = mid + 1;
        else
            right = mid;
    }
    // Insertion à la position trouvée
    mainSeq.insert(mainSeq.begin() + left, value);
}
