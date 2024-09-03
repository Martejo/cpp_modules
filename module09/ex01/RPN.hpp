#ifndef RPN_HPP
#define RPN_HPP

// Codes ANSI pour les couleurs
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BOLD    "\033[1m"

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <exception>
#include <climits>
#include <cstdlib>
#include <cctype>

void rpnProcess(const std::string &av);


#endif