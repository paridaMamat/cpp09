/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaimait <pmaimait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:29:33 by pmaimait          #+#    #+#             */
/*   Updated: 2023/12/20 11:23:38 by pmaimait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

int isPositiveInteger(const std::string& str) {
    if (str.empty())
        throw std::invalid_argument("Error: Invalid input argument, should not have argument empty");
    for (size_t i = 0; i < str.length(); ++i) 
    {
        if (!isdigit(str[i])) {
            throw std::invalid_argument("Error: Invalid input argument. it should be a positive integer.");
        }
    }
    int value = atoi(str.c_str());
    if (value == -1)
        throw std::invalid_argument("Error: integer is out of range."); 
    return value;
}
int     main(int ac, char **av)
{
    try
    {
        if (ac < 2)
            throw std::invalid_argument("Error: No input sequence provided."); 

        std::vector<int> vec;
        std::deque<int> deq;
        for (int i = 1; i < ac; i++)
        {
            std::string str;
            str = av[i];
            int value = isPositiveInteger(str);
            vec.push_back(value);
            deq.push_back(value);   
        }
        std::cout << "Before: ";
        for (size_t i = 1; i < vec.size(); i++)
        {
             std::cout << vec[i] << " " ;
        }     
        std::cout <<std::endl;
        PmergeMe a(vec, deq);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}