/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaimait <pmaimait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:02:08 by pmaimait          #+#    #+#             */
/*   Updated: 2023/12/18 11:52:14 by pmaimait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include<iostream>
#include <stack>
#include <iostream>
#include <stdexcept>
#include <cctype>

class RPN : public std::stack<long long>
{
    private:
        long long _result;
        std::string _src;
        
    public:
        RPN();
        RPN(std::string &src);
        RPN(const RPN &obj);
        RPN&	operator=(const RPN &obj);
        ~RPN();

};
#endif