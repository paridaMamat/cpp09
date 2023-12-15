/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaimait <pmaimait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:25:48 by pmaimait          #+#    #+#             */
/*   Updated: 2023/12/15 16:21:16 by pmaimait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

BitcointExchange::BitcointExchange(){}
BitcointExchange::BitcointExchange(const BitcointExchange &obj){*this = obj;}
BitcointExchange &BitcointExchange::operator=(const BitcointExchange &obj)
{
    InputData = obj.InputData;
    return *this;
}
BitcointExchange::~BitcointExchange(){}

BitcointExchange::BitcointExchange(const std::string &src)
{
    std::ifstream dataBase(src.c_str());
    if (not dataBase.good())
        throw (std::runtime_error("[ERROR] Error opening data.csv"));
    
    std::string     line;
    std::pair<std::string, float>   element;
    
    std::getline(dataBase, line);
    while (std::getline(dataBase, line))
    {
        if (line.find(',') != std::string::npos)
        {
            element.first = line.substr(0, line.find(','));
            element.second = std::atof(line.substr(line.find(',') + 1).c_str());
            insert(element);
        }
    }
    dataBase.close();
}  
bool    CheckFirstLine(std::string line)
{
    // Remove spaces from the line
    std::string cleanedLine;
    for (size_t i = 0; i < line.size(); ++i) 
    {
        if (!std::isspace(line[i])) 
        {
            cleanedLine += line[i];
        }
    }
    // std::cout << cleanedLine << std::endl;
    if (cleanedLine == "date|value")
        return(true);
    else
        return(false);
}
void    BitcointExchange::fill(const std::string &sourceFile)
{
    std::ifstream   file(sourceFile.c_str());
    if (not file.good())
        throw (std::runtime_error("Error: could not open file."));
    
    std::string     line;
    std::pair<std::string, double> element;
    
    
    std::getline(file, line);
    if (CheckFirstLine(line) == false)
        throw (std::runtime_error("Header's format is not correct"));
    while (std::getline(file, line))
    {
        parsing(line);
    }
    // for (InputData::iterator it = InputData.begin(); it != InputData.end(); ++it) {
    //     std::cout << "date: " << it->first << ", Value: " << it->second << std::endl;
    // }
    file.close();
}

void    BitcointExchange::parsing(std::string line)
{
    // Remove spaces from the line
    std::string cleanedLine;
    for (size_t i = 0; i < line.size(); ++i) {
        if (!std::isspace(line[i])) {
            cleanedLine += line[i];
        }
    }
    std::pair<std::string, float> element;
    struct tm date;
    float value;
    memset(&date, 0, sizeof(date)); // Initialize date structure

    // Use sscanf to parse the date and value parts
    if (std::sscanf(cleanedLine.c_str(), "%4d-%2d-%2d|%f", &date.tm_year, &date.tm_mon, &date.tm_mday, &value) == 4) 
    {
        if (std::mktime(&date) == -1 || date.tm_year < 2009 || date.tm_year > 2022)  
        {
            date.tm_year -= 1900; // Adjust the year
            date.tm_mon -= 1;     // Adjust the month
            element.first = "Error: bad input => " + tmToString(date);
            element.second = -1;
        }
        else if (value < 0)
        {
            element.first = "Error: not a positive number.";
            element.second = -1;
        }
        else if (value > 1000)
        {
            element.first = "Error: too large a number.";
            element.second = -1;
        }
        else
        {
            element.first = cleanedLine.substr(0, line.find('|') - 1);
            element.second = value; 
        }     
    }
    else
        {
            element.first =  "Error: bad input => " + cleanedLine;
            element.second = -1;
        }
    display(element.first, element.second);
}


std::string tmToString(const std::tm& date) 
{
    char buffer[80]; // Sufficient size for most date formats

    // Use strftime to format struct tm as a string
    
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", &date);
    return (buffer);
}

void BitcointExchange::display(std::string date, float value)
{

    
        if (value == -1)
        {
            std::cout << date << std::endl;
        }
        else
        {
            BitcointExchange::iterator DB = find(date);
            if (DB == end())
            {
                DB = lower_bound(date);
                DB --;
                if (date == "2009-01-01")
                    DB = begin();
            }
            std::cout << date << " => " << value << " = ";
            std::cout << DB->second * value << std::endl;
        
        }
}

