#include "Serialization.hpp"
#include <iostream>
#include "Data.hpp"


int main(int ac, char **av)
{
        if (ac == 2)
        {
                Data data(av[1]);
                std::cout << "BEFORE serialization " << std::endl;
                std::cout << "Data str = " << data << std::endl;

                uintptr_t ptr = Serialization::serialize(&data);
                data = *Serialization::deserialize(ptr);
                std::cout << std::endl;
                std::cout << "---\n\nAFTER serialization " << std::endl;
                std::cout << "Data str = " << data << std::endl;
        }
        else{

                std::cout << "Error: usage: ./serialization <string> " << std::endl;
        }


}