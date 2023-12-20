/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaimait <pmaimait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:02:00 by pmaimait          #+#    #+#             */
/*   Updated: 2023/12/20 19:14:54 by pmaimait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/RPN.hpp"

RPN::RPN(){}
RPN::RPN(const RPN &obj){*this = obj;}
RPN &RPN::operator=(const RPN &obj)
{
    _result = obj._result;
    return *this;
}
RPN::~RPN(){}

std::string nospace(std::string &src)
{
    std::string cleanedLine;
    for (size_t i = 0; i < src.size(); ++i) 
    {
        if (!std::isspace(src[i])) 
        {
            cleanedLine += src[i];
        }
    }
    return cleanedLine;
}

bool isOps(char a)
{
    if (a != '+' && a != '-' && a != '*' && a != '/')
        return false;
    return true;
}

bool isValidString(const std::string& input) {
    int countNumber = 0;
    int countOps = 0;
    for (size_t i = 0; i < input.size(); i ++)
    {
        if (isdigit(input[i]))
            countNumber++;
        if (isOps(input[i]))
            countOps++;
        if (!isdigit(input[i]) && (isOps(input[i]) == false))
            throw (std::runtime_error("Error"));  
    }  
    // Check if the string starts with two number
    if ((!isdigit(input[0]) && !isdigit(input[1]) ) || (countNumber != (countOps + 1)) || !isOps(input[input.size() - 1]))
        return false;
    return true;
}

int charToInt(char c) {
    return static_cast<int>(c - '0');
}

int calcule(int a, int b, char ope)
{
    if (ope == '+')
        return a + b;
    if (ope == '-')
        return a - b;
    if (ope == '*')
        return a * b;
    if (ope == '/')
    {
        if (b != 0)
            return a / b;
        else 
            throw std::invalid_argument("Division by zero");
    }
    throw std::invalid_argument("Invalid operator");
}

RPN::RPN(std::string &src)
{
    _src = nospace(src);
    if(_src == "")
        throw (std::runtime_error("[ERROR] there is nothing in argument, write something"));
    if (!isValidString(_src))
        throw (std::runtime_error("Error")); 

    // Create a stack to store characters
    std::stack<int> numberStack;
    size_t i = 0;
    int tmp = 0;
    while (i < _src.size())
    {
        while (isdigit(_src[i]))
        {
            // std::cout << _src[i] - '0' << std::endl;
            numberStack.push(_src[i] - '0');
            i++;
        }
        
        if (isOps(_src[i]) == true)
        {
            int pos1 = numberStack.top();
            numberStack.pop();
            int pos2 = numberStack.top();
            numberStack.pop();
            // std::cout << "pos1 = " << pos1 << " pos2 = " << pos2 << " ope = " << _src[i] << std::endl;
            tmp = calcule(pos2, pos1, _src[i]);
            // std::cout << "result = " << tmp << std::endl;
            numberStack.push(tmp);
        }
        i++;
    }
    std::cout << numberStack.top() <<std::endl;
}