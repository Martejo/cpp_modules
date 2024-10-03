#include <iostream>
#include <ctime>
#include <sstream>
#include <fstream>
#include <map>
#include <string>
#include <stdexcept>
#include <iomanip>
#include <climits>
#include <cstring> 
#include <cstdio>

// Fonction pour vérifier le nombre d'arguments
void checkNbArgs(int ac);

// Fonction pour ouvrir un fichier
std::ifstream& extractFile(std::ifstream& filestream, const char *filename);

// Fonction pour parser une date au format "YYYY-MM-DD" en std::tm
std::tm parseDate(const std::string& date);


// Comparateur pour std::tm (on appelle ceci un foncteur)
struct tmCompare {
    bool operator()(const std::tm& lhs, const std::tm& rhs) const {
        if (lhs.tm_year != rhs.tm_year)
            return lhs.tm_year < rhs.tm_year;
        if (lhs.tm_mon != rhs.tm_mon)
            return lhs.tm_mon < rhs.tm_mon;
        return lhs.tm_mday < rhs.tm_mday;
    }
};
/*
Définition du foncteur avec l'opérateur () :
Lorsque tu définis une classe ou une structure et que tu y ajoutes une surcharge de l'opérateur (), 
tu transformes cette classe ou structure en un foncteur. 
*/

std::map<std::tm, float, tmCompare> mapExchangeRate(std::ifstream &dataFile);
bool isValidValue(const std::string& valueStr, float& value);
bool isValidDate(std::tm &tm);
void checkHeaderInFile(std::string firstLine);
void displayRates(std::string &line, std::ifstream &inputFile, const std::map<std::tm, float, tmCompare>& exchangeRates);
void displayExchangeRate(const std::map<std::tm, float, tmCompare>& exchangeRates, std::ifstream &inputFile);