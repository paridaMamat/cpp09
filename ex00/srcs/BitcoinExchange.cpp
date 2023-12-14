/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaimait <pmaimait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:25:48 by pmaimait          #+#    #+#             */
/*   Updated: 2023/12/14 19:03:41 by pmaimait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

BitcointExchange::BitcointExchange(){}
BitcointExchange::BitcointExchange(const BitcointExchange &obj){*this = obj;}
BitcointExchange &BitcointExchange::operator=(const BitcointExchange &obj)
{
    (void)obj;
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
    float value;
    memset(&date, 0, sizeof(date)); // Initialize date structure

    // Use sscanf to parse the date and value parts
    if (std::sscanf(cleanedLine.c_str(), "%4d-%2d-%2d|%f", &date.tm_year, &date.tm_mon, &date.tm_mday, &value) == 4) 
    {
        
        // date.tm_year -= 1900; // Adjust the year
        // date.tm_mon -= 1;     // Adjust the month
        // std::cout << tmToString(date) << std::endl;
        
        if (std::mktime(&date) == -1 || date.tm_year < 2009 || date.tm_year > 2022)  
        {
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
    // std::cout << "when save " << element.first << "|" << element.second <<std::endl;
    display(element.first, element.second);
    // for (InputData::iterator it = InputData.begin(); it != InputData.end(); ++it) {
    //     std::cout << "date: " << it->first << ", Value: " << it->second << std::endl;
    // }  
}


std::string tmToString(const std::tm& date) 
{
    char buffer[80]; // Sufficient size for most date formats

    // Use strftime to format struct tm as a string
    
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", &date);

    // Compare the formatted string with the input string
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
            std::cout << date << " => " << value << " = ";
            BitcointExchange::iterator DB = find(date);
            if (DB == end())
            {
                struct tm  tmp;
                memset(&tmp, 0, sizeof(tmp)); 
                if (std::sscanf(date.c_str(), "%d-%d-%d", &tmp.tm_year, &tmp.tm_mon, &tmp.tm_mday) != 3)
                {
                    // Handle the error, print a message or throw an exception
                    std::cerr << "Error parsing date: " << date << std::endl;
                }
                // tmp.tm_year += 1900;
                // tmp.tm_mon += 1;
                while (DB == end())
                {
                    tmp.tm_mday--;
                    DB = find(tmToString(tmp));
                }
            }
            std::cout << DB->second * value << std::endl;
        }
}

