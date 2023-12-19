/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaimait <pmaimait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:29:33 by pmaimait          #+#    #+#             */
/*   Updated: 2023/12/19 14:46:27 by pmaimait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

int isPositiveInteger(const std::string& str) {
    if (str.empty())
        throw std::invalid_argument("Error: Invalid input argument.");
    for (size_t i = 0; i < str.length(); ++i) 
    {
        if (!isdigit(str[i])) {
            throw std::invalid_argument("Error: Invalid input argument.");
        }
    }
    int value = atoi(str.c_str());
    if (value < 0 || value > INT_MAX)
        throw std::invalid_argument("Error: it should be a positive integer."); 
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
        PmergeMe(vec, deq);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}