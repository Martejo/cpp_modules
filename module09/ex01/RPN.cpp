#include "RPN.hpp"

bool ifOperator(const char &value)
{
    return (value == '+' || value == '-' || value == '/' || value == '*');
}

int calculateValues(int &a, int &b, char &sign)
{
    double result;
    if (sign == '+')
        result = static_cast<double>(a) + static_cast<double>(b);
    else if (sign == '*')
        result = static_cast<double>(a) * static_cast<double>(b);
    else if (sign == '-')
        result = static_cast<double>(a) - static_cast<double>(b);
    else
    {
        if (b == 0)
            throw(std::exception()); // Impossible de diviser par 0
        result = static_cast<double>(a) / static_cast<double>(b);
    }
    // std::cout << std::fixed << INT_MAX << "  " << result << std::endl;//
    if (result > static_cast<double>(INT_MAX) || result < static_cast<double>(INT_MIN))
            throw(std::exception()); // Overflow ou underflow

    return (static_cast<int>(result));
}

void rpnProcess(const std::string &av)
{
    std::istringstream rpn(av);
    std::istream_iterator<std::string> begin(rpn);
    std::istream_iterator<std::string> end;
    std::stack<int> stack;

    while (begin != end)
    {
        std::string value = *begin;

        if (isdigit(value[0]))
            stack.push(std::atoi(value.c_str()));
        else if (ifOperator((char)value[0]))
        {
            if (stack.size() < 2)
                throw std::exception();

            int b = stack.top();
            stack.pop();
            int a = stack.top();
            stack.pop();
            
            // Effectuer l'opération et pousser le résultat sur la pile
            try{
                int result = calculateValues(a, b, value[0]);
                stack.push(result);
            }
            catch(std::exception &e){
                throw std::exception();
            }
        }
        ++begin;
    }
    if (stack.size() != 1)
        throw std::exception();
    std::cout << stack.top() << std::endl;
}

