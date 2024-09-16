#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <stdexcept>
#include <sstream>
#include <cctype>
#include <climits>

//Manage Vector
void printVector(const std::vector<unsigned int>& vec);
std::vector<unsigned int> generateJacobsthal(unsigned int n);
void fordJohnsonSort(std::vector<unsigned int>& arr);

//Manage List
void printList(const std::list<unsigned int>& lst);
std::list<unsigned int> generateJacobsthal(int n);
void fordJohnsonSort(std::list<unsigned int>& lst);


#endif