#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(RPN const& ref)
{
    *this = ref;
}

RPN::~RPN() {}

RPN& RPN::operator=(RPN const& ref)
{
    if (this != &ref) {
        *this = ref;
    }
    return (*this);
}

int RPN::calculte(std::string arg)
{
    std::stack<int> tmpStack;
    std::stringstream ss(arg);
    std::string tmp;
    while (std::getline(ss, tmp, ' ')) {
        if (tmp.length() != 1)
            throw std::runtime_error("Error");
        if (tmp[0] > '0' && tmp[0] <= '9')
            tmpStack.push(tmp[0] - '0');
        else if (tmp[0] == '*' || tmp[0] == '/' || tmp[0] == '+' || tmp[0] == '-') {
            if (tmpStack.size() < 2)
                throw std::runtime_error("Error");
            int b = tmpStack.top();
            tmpStack.pop();
            int a = tmpStack.top();
            tmpStack.pop();
            switch (tmp[0]) {
            case '*':
                tmpStack.push(a * b);
                break;
            case '/':
                if (b == 0)
                    throw std::runtime_error("Division by zero");
                tmpStack.push(a / b);
                break;
            case '+':
                tmpStack.push(a + b);
                break;
            case '-':
                tmpStack.push(a - b);
                break;
            default:
                break;
            }
        }
        else {
            throw std::runtime_error("Error");
        }
    }
    if (tmpStack.size() != 1)
        throw std::runtime_error("Error");
    return tmpStack.top();
}
