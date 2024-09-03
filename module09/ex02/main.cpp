#include <algorithm>
#include <vector>
#include <list>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <type_traits>

template<typename Container>
Container getIntegerSequence(char *av[]) {
    Container container;
    int i = 1;
    char *ptr;
    while (av[i]) {
        int val = std::strtol(av[i], &ptr, 10);
        if (*ptr != '\0' || val < 0) {
            throw std::runtime_error("Error");
        }
        container.push_back(val);
        i++;
    }
    return container;
}

template<typename Container>
std::vector<std::pair<typename Container::value_type, typename Container::value_type>> createAndSortPairs(Container& container) {
    std::vector<std::pair<typename Container::value_type, typename Container::value_type>> containerPair;
    typename Container::iterator it = container.begin();
    while (it != container.end()) {
        typename Container::value_type first = *it;
        ++it;
        if (it != container.end()) {
            typename Container::value_type second = *it;
            containerPair.push_back(std::make_pair(first, second));
            if (containerPair.back().first < containerPair.back().second) {
                std::swap(containerPair.back().first, containerPair.back().second);
            }
            ++it;
        }
    }
    return containerPair;
}

template<typename Container>
void merge(std::vector<std::pair<typename Container::value_type, typename Container::value_type>>& array, int begin, int mid, int end) {
    typedef std::pair<typename Container::value_type, typename Container::value_type> PairType;
    std::vector<PairType> leftArray(array.begin() + begin, array.begin() + mid + 1);
    std::vector<PairType> rightArray(array.begin() + mid + 1, array.begin() + end + 1);

    size_t leftIndex = 0, rightIndex = 0, mergedIndex = begin;

    while (leftIndex < leftArray.size() && rightIndex < rightArray.size()) {
        if (leftArray[leftIndex].first <= rightArray[rightIndex].first) {
            array[mergedIndex++] = leftArray[leftIndex++];
        } else {
            array[mergedIndex++] = rightArray[rightIndex++];
        }
    }
    while (leftIndex < leftArray.size()) {
        array[mergedIndex++] = leftArray[leftIndex++];
    }
    while (rightIndex < rightArray.size()) {
        array[mergedIndex++] = rightArray[rightIndex++];
    }
}

template<typename Container>
void mergeSort(std::vector<std::pair<typename Container::value_type, typename Container::value_type>>& array, int begin, int end) {
    if (begin >= end) return;
    int mid = begin + (end - begin) / 2;
    merge<Container>(array, begin, mid, end);
}

template<typename Container>
void createMainChainAndPend(std::vector<std::pair<typename Container::value_type, typename Container::value_type>>& containerPair,
                            Container& mainChain, Container& pend) {
    if (!containerPair.empty()) {
        mainChain.push_back(containerPair[0].second);
        for (size_t i = 0; i < containerPair.size(); ++i) {
            mainChain.push_back(containerPair[i].first);
            if (i > 0) {
                pend.push_back(containerPair[i].second);
            }
        }
    }
}

template<typename Container>
std::vector<int> generateJacobsthal(int n) {
    std::vector<int> jacobSequence;
    int a = 0, b = 1;
    while (jacobSequence.size() < static_cast<size_t>(n)) {
        jacobSequence.push_back(a);
        int next = a + 2 * b;
        a = b;
        b = next;
    }
    return jacobSequence;
}

template<typename Container>
void insertToMainChain(Container& mainChain, Container& pend, std::vector<int>& positions) {
    size_t addedCount = 0;
    for (size_t i = 0; i < positions.size(); ++i) {
        typename Container::iterator pendIt = pend.begin();
        std::advance(pendIt, positions[i] - 1);

        typename Container::value_type target = *pendIt;

        // Trouver la position d'insertion pour la liste
        typename Container::iterator insertPos = mainChain.begin();
        size_t pos = positions[i] + addedCount;
        std::advance(insertPos, pos);

        mainChain.insert(insertPos, target);
        addedCount++;
    }
}

int main(int argc, char *argv[]) {
    try {
        if (argc < 2) {
            std::cerr << "Usage: " << argv[0] << " [numbers...]" << std::endl;
            return 1;
        }

        // Tester avec std::vector<int>
        std::vector<int> vec = getIntegerSequence<std::vector<int> >(argv);
        std::cout << "Testing with std::vector<int>:" << std::endl;
        if (vec.size() == 1) {
            std::cout << vec.front() << std::endl;
        } else {
            std::vector<std::pair<int, int> > vecPair = createAndSortPairs(vec);
            mergeSort<std::vector<int> >(vecPair, 0, vecPair.size() - 1);

            std::vector<int> mainChain;
            std::vector<int> pend;
            createMainChainAndPend<std::vector<int> >(vecPair, mainChain, pend);

            std::vector<int> jacobSequence = generateJacobsthal<std::vector<int> >(pend.size());
            insertToMainChain<std::vector<int> >(mainChain, pend, jacobSequence);

            for (std::vector<int>::iterator it = mainChain.begin(); it != mainChain.end(); ++it) {
                std::cout << *it << " ";
            }
            std::cout << std::endl;
        }

        // Tester avec std::list<int>
        std::list<int> lst = getIntegerSequence<std::list<int> >(argv);
        std::cout << "Testing with std::list<int>:" << std::endl;
        if (lst.size() == 1) {
            std::cout << lst.front() << std::endl;
        } else {
            std::vector<std::pair<int, int> > lstPair = createAndSortPairs(lst);
            mergeSort<std::list<int> >(lstPair, 0, lstPair.size() - 1);

            std::list<int> mainChain;
            std::list<int> pend;
            createMainChainAndPend<std::list<int> >(lstPair, mainChain, pend);

            std::vector<int> jacobSequence = generateJacobsthal<std::list<int> >(pend.size());
            insertToMainChain<std::list<int> >(mainChain, pend, jacobSequence);

            for (std::list<int>::iterator it = mainChain.begin(); it != mainChain.end(); ++it) {
                std::cout << *it << " ";
            }
            std::cout << std::endl;
        }

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
