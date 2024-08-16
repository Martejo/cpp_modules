#include "ScalarConverter.hpp"

int main(int ac, char **av) 
{
    if(ac == 2 && av[1][0] != '\0'){
        try {ScalarConverter::convert(av[1]);}
        catch(const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    } else {
        std::cerr << "Error: bad number of arguments usage: ./scalar_converter <string (not null)>"  << std::endl;
    }
    return 0;
}