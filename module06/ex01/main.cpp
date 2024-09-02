#include <iostream>
#include "Serialization.hpp"
#include "Data.hpp"

// Codes ANSI pour les couleurs
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

void printHeader(const std::string &title) {
    std::cout << CYAN << "==================== " << title << " ====================" << RESET << std::endl;
}

void printData(const Data *data) {
    std::cout << GREEN << "Data Structure:" << RESET << std::endl;
    std::cout << YELLOW << "Content: " << WHITE << *data << RESET << std::endl;
}

int main()
{
    printHeader("Original Data");
    
    // Créer une instance de Data
    Data myData("Test String");
    printData(&myData);
    
    std::cout << std::endl;

    printHeader("Serialization Process");

    // Sérialiser
    uintptr_t raw = Serialization::serialize(&myData);
    std::cout << BLUE << "Serialized uintptr_t value: " << WHITE << raw << RESET << std::endl;
    
    std::cout << std::endl;

    printHeader("Deserialization Process");

    // Désérialiser
    Data* deserializedData = Serialization::deserialize(raw);
    std::cout << BLUE << "Pointer after deserialization: " << WHITE << deserializedData << RESET << std::endl;

    std::cout << std::endl;

    printHeader("Comparison and Result");

    // Vérifier que le pointeur désérialisé est identique au pointeur original
    if (deserializedData == &myData) {
        std::cout << GREEN << "The pointers are equal.\n" << RESET << std::endl;
        printData(deserializedData);
    } else {
        std::cout << RED << "Error: The pointers are not equal." << RESET << std::endl;
    }

    return 0;
}
