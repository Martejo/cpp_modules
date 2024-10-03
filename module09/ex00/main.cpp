#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
    try {
        checkNbArgs(ac);
        std::ifstream inputFile;
        std::ifstream dataFile;
        extractFile(inputFile, av[1]);
        extractFile(dataFile, "data.csv");
        // std::cout << "test" <<std::endl;
        std::map<std::tm, float, tmCompare> exchangeRates = mapExchangeRate(dataFile);
        displayExchangeRate(exchangeRates, inputFile);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}