#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>
#include <stdexcept>

std::vector<int> getIntegerSequence(char *av[]) {
    std::vector<int> vec;
    int i = 1;
    char *ptr;
    while (av[i]) {
        int val = std::strtol(av[i], &ptr, 10);
        if (*ptr != '\0' || val < 0) {
            throw std::runtime_error("Error");
        }
        vec.push_back(val);
        i++;
    }
    return vec;
}

std::vector<std::pair<int, int>> createAndSortPairs(std::vector<int>& vec) {
    std::vector<std::pair<int, int>> vecPair;
    for (size_t i = 0; i < vec.size() / 2; i++) {
        vecPair.push_back(std::make_pair(vec[2 * i], vec[2 * i + 1]));
        if (vecPair.back().first < vecPair.back().second) {
            std::swap(vecPair.back().first, vecPair.back().second);
        }
    }
    return vecPair;
}

void merge(std::vector<std::pair<int, int>>& array, int begin, int mid, int end) {
    std::vector<std::pair<int, int>> leftArray(array.begin() + begin, array.begin() + mid + 1);
    std::vector<std::pair<int, int>> rightArray(array.begin() + mid + 1, array.begin() + end + 1);

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

void mergeSort(std::vector<std::pair<int, int>>& array, int begin, int end) {
    if (begin >= end) return;
    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

void createMainChainAndPend(std::vector<std::pair<int, int>>& vecPair, std::vector<int>& mainChain, std::vector<int>& pend) {
    if (!vecPair.empty()) {
        mainChain.push_back(vecPair[0].second);
        for (size_t i = 0; i < vecPair.size(); ++i) {
            mainChain.push_back(vecPair[i].first);
            if (i > 0) {
                pend.push_back(vecPair[i].second);
            }
        }
    }
}

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

void insertToMainChain(std::vector<int>& mainChain, std::vector<int>& pend, std::vector<int>& positions) {
    size_t addedCount = 0;
    for (size_t i = 0; i < positions.size(); ++i) {
        int target = pend[positions[i] - 1];
        size_t endPos = positions[i] + addedCount;
        auto it = std::lower_bound(mainChain.begin(), mainChain.begin() + endPos, target);
        mainChain.insert(it, target);
        addedCount++;
    }
}

int main(int argc, char *argv[]) {
    try {
        if (argc < 2) {
            std::cerr << "Usage: " << argv[0] << " [numbers...]" << std::endl;
            return 1;
        }

        std::vector<int> vec = getIntegerSequence(argv);

        if (vec.size() == 1) {
            std::cout << vec[0] << std::endl;
            return 0;
        }

        auto vecPair = createAndSortPairs(vec);

        mergeSort(vecPair, 0, vecPair.size() - 1);

        std::vector<int> mainChain;
        std::vector<int> pend;
        createMainChainAndPend(vecPair, mainChain, pend);

        std::vector<int> jacobSequence = generateJacobsthal(pend.size());

        insertToMainChain(mainChain, pend, jacobSequence);

        for (int num : mainChain) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
