/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaimait <pmaimait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:02:00 by pmaimait          #+#    #+#             */
/*   Updated: 2023/12/18 11:29:59 by pmaimait         ###   ########.fr       */
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

#include <iostream>
#include <stdexcept>
#include <cctype>

bool isValidString(const std::string& input) {
    for (size_t i = 1; i < input.size(); i ++)
    {
        if (!isdigit(input[i]) && (input[i] != '+' && input[i] != '-' && input[i] != '*' && input[i] != '/'))
            throw (std::runtime_error("Error"));  
    }  
  
    // Check if the string starts with two number
    if ((!isdigit(input[0]) && !isdigit(input[1]) )|| (input.size() % 2 == 0))
        return false;

    // Check if the characters in odd positions are digits
    for (size_t i = 1; i < input.size(); i += 2) {
        if (!isdigit(input[i]))
            return false;
    }

    // Check if the characters in even positions are operators
    for (size_t i = 2; i < input.size(); i += 2) {
        if (input[i] != '+' && input[i] != '-' && input[i] != '*' && input[i] != '/') 
            return false;
    }
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
        throw (std::runtime_error("0")); 

    // Create a stack to store characters
    std::stack<char> charStack;

    // Save characters in the stack in reverse order
    for (int i = _src.size() - 1; i >= 0; --i) {
        charStack.push(_src[i]);
    }
    
    if(!charStack.empty())
    {
        int pos1 = charToInt(charStack.top());
        charStack.pop();
        int pos2 = charToInt(charStack.top());
        charStack.pop();
        char ope = charStack.top();
        charStack.pop();
        int tmp = calcule(pos1, pos2, ope);
        while(!charStack.empty())
        {
            int pos2 = charToInt(charStack.top());
            charStack.pop();
            tmp = calcule(tmp, pos2, charStack.top());
            charStack.pop();
        }
        std::cout << tmp <<std::endl;
    }
}