/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaimait <pmaimait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:34:10 by pmaimait          #+#    #+#             */
/*   Updated: 2023/12/14 19:04:01 by pmaimait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/BitcoinExchange.hpp"

void    InvalidInput(int ac)
{
    if (ac != 2)
    {
        if (ac < 2)
            throw (std::runtime_error("[ERROR] Need an argument"));
        else
            throw (std::runtime_error("[ERROR] Too many argument"));
    }
}

int main(int ac, char **av)
{
   try
    { 
        InvalidInput(ac);
        BitcointExchange btc ("data.csv");
        btc.fill(av[1]);
        return (0);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}