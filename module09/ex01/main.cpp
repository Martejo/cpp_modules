#include "RPN.hpp"

void rpnAnalysisFormat(const std::string &av)
{
    std::istringstream rpn(av);
    std::istream_iterator<std::string> begin(rpn);
    std::istream_iterator<std::string> end;

    while (begin != end)
    {
        std::string value = *begin;
        // Vérifie si la taille est 1 et que ce n'est pas un chiffre ou un opérateur
        if (value.size() > 1 || (!isdigit(value[0]) && value != "+" && value != "-" && value != "*" && value != "/"))
            throw(std::exception());
        ++begin;
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << RED << BOLD << "This RPN program accepts only one argument in inverted Polish notation." << RESET << std::endl;
        return (1);
    }
    try{
        rpnAnalysisFormat(argv[1]);
        rpnProcess(argv[1]);
    }catch(std::exception &e){
        std::cerr << "Erreur" << std::endl;
    }
}