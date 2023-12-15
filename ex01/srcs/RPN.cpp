/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaimait <pmaimait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:02:00 by pmaimait          #+#    #+#             */
/*   Updated: 2023/12/15 16:59:46 by pmaimait         ###   ########.fr       */
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

RPN::RPN(std::string &src)
{
    _src = nospace(src);
    if(_src == "")
        throw (std::runtime_error("[ERROR] there is only space in argument, write something"));
}