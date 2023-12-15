/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaimait <pmaimait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:25:42 by pmaimait          #+#    #+#             */
/*   Updated: 2023/12/15 16:20:41 by pmaimait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

# include<iostream>
# include<algorithm>
# include<string>
# include<cstring>
# include<cstdlib>
# include <fstream>
# include<map>
#include <sstream>
#include <ctime>
#include <iomanip>
#include <ctime>
#include <cstdio>

typedef std::map<std::string, float>  InputData;
bool    CheckFirstLine(std::string line);
std::string tmToString(const std::tm& date);

class BitcointExchange : public std::map<std::string, float>
{
    private :
        InputData InputData;
        // struct tm date;
        BitcointExchange();

    public :
        BitcointExchange(const std::string &src);
        BitcointExchange(const BitcointExchange &obj);
        BitcointExchange& operator=(const BitcointExchange &obj);
        ~BitcointExchange(); 
        
        void fill(const std::string &sourceFile); 
        void parsing(std::string line);
        void display(std::string date, float value);   
};
#endif