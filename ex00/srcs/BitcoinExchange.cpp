/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaimait <pmaimait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:25:48 by pmaimait          #+#    #+#             */
/*   Updated: 2023/12/12 16:04:59 by pmaimait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

BitcointExchange::BitcointExchange(){}
BitcointExchange::BitcointExchange(const BitcointExchange &obj){*this = obj;}
BitcointExchange &BitcointExchange::operator=(const BitcointExchange &obj){
    *this = obj;
}

BitcointExchange::BitcointExchange(const std::string &src){
    std::ifstream dataBase(src.c_str());
    if (not dataBase.good())
        throw (std::runtime_error("[ERROR] Error opening data.csv"));
    
}