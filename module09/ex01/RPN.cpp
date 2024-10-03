#include "RPN.hpp"

bool isOperator(const char &value)
{
    return (value == '+' || value == '-' || value == '/' || value == '*');
}

void    detectBufferOverflow(double result)
{
    if (result > static_cast<double>(INT_MAX) || result < static_cast<double>(INT_MIN))
            throw(std::exception());
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
    try{detectBufferOverflow(result);}
    catch(std::exception& e){throw(std::exception());}

    return (static_cast<int>(result));
}

void rpnProcess(const std::string &av)
{
    std::istringstream rpn(av);
    std::string value;
    std::stack<int> stack;

    while (rpn >> value)
    {

        if (isdigit(value[0]))
            stack.push(std::atoi(value.c_str()));
        else if (isOperator(static_cast<char>(value[0])))
        {
            if (stack.size() < 2)
                throw std::exception();

            //extract the 2 digits at the top of the stack
            int b = stack.top();stack.pop();
            int a = stack.top();stack.pop();
            
            try{
                //can return an exception for instance if the calculation leads to an overflow or DIV/0
                int result = calculateValues(a, b, value[0]);
                //push the result on the stack
                stack.push(result);
            }
            catch(std::exception &e){
                throw std::exception();
            }
        }
    }
    //Error : nb of operands doesn't match nb of operators
    if (stack.size() != 1)
        throw std::exception();
    //display the result
    std::cout << stack.top() << std::endl;
}