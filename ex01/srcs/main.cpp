/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaimait <pmaimait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:02:04 by pmaimait          #+#    #+#             */
/*   Updated: 2023/12/15 16:45:46 by pmaimait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/RPN.hpp"

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
        RPN rpn (av[1]);
        return (0);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}