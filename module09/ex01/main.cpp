#include "RPN.hpp"

void rpnCheckFormat(const std::string &av)
{
    std::istringstream rpn(av);
    std::string value;

    while (rpn >> value)
    {
        if (value.size() > 1 || (!isdigit(value[0]) && value != "+" && value != "-" && value != "*" && value != "/"))
            throw(std::exception());
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << BOLD << RED << "Error: This program need 1 argument\n Usage: ./RPN <string in rpn>" << RESET << std::endl;
        return (1);
    }
    try{
        rpnCheckFormat(argv[1]);
        rpnProcess(argv[1]);
    }catch(std::exception &e){
        std::cerr << BOLD << RED << "Erreur" << RESET << std::endl;
    }
    return(0);
}