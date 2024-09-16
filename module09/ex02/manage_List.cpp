#include "PmergeMe.hpp"


void printList(const std::list<unsigned int>& lst) {
    for (std::list<unsigned int>::const_iterator it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

std::list<unsigned int> generateJacobsthalList(int n) {
    std::list<unsigned int> jacobsthal;
    int a = 0, b = 1;
    while (a < n) {
        jacobsthal.push_back(a);
        int next = a + 2 * b;
        a = b;
        b = next;
    }
    return jacobsthal;
}

void fordJohnsonSort(std::list<unsigned int>& lst) {
    if (lst.size() <= 1) return;

    bool isOdd = lst.size() % 2 != 0;
    unsigned int laggard = 0;

    if (isOdd) {
        laggard = lst.back();
        lst.pop_back();
    }

    std::list<std::pair<unsigned int, unsigned int> > pairs;
    std::list<unsigned int>::iterator it = lst.begin();
    while (it != lst.end()) {
        unsigned int first = *it;
        ++it;
        unsigned int second = *it;
        ++it;
        pairs.push_back(std::make_pair(std::min(first, second), std::max(first, second)));
    }

    std::list<unsigned int> S;
    for (std::list<std::pair<unsigned int, unsigned int> >::iterator it = pairs.begin(); it != pairs.end(); ++it) {
        S.push_back(it->second);
    }
    S.sort();

    std::list<unsigned int> pend;
    for (std::list<std::pair<unsigned int, unsigned int> >::iterator it = pairs.begin(); it != pairs.end(); ++it) {
        pend.push_back(it->first);
    }

    std::list<unsigned int> jacobsthalSeq = generateJacobsthalList(pend.size());
    // for (std::list<unsigned int>::reverse_iterator rit = jacobsthalSeq.rbegin(); rit != jacobsthalSeq.rend(); ++rit) {
    //     if (*rit < static_cast<unsigned int>(pend.size())) {
    //         std::list<unsigned int>::iterator pendIt = pend.begin();
    //         std::advance(pendIt, *rit);
    //         S.insert(std::lower_bound(S.begin(), S.end(), *pendIt), *pendIt);
    //     }
    // }
    for (std::list<unsigned int>::iterator it = pend.begin(); it != pend.end(); ++it) {
        S.insert(std::lower_bound(S.begin(), S.end(), *it), *it);
    }

    if (isOdd) {
        S.insert(std::lower_bound(S.begin(), S.end(), laggard), laggard);
    }

    lst = S;
}