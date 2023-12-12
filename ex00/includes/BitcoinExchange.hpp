/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaimait <pmaimait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:25:42 by pmaimait          #+#    #+#             */
/*   Updated: 2023/12/12 16:04:24 by pmaimait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

# include<iostream>
# include<algorithm>
#include <fstream>
# include<map>

class BitcointExchange : public std::map<std::string, float>
{
    private :
        BitcointExchange();

    public :
        BitcointExchange(const std::string &src);
        BitcointExchange(const BitcointExchange &obj);
        BitcointExchange& operator=(const BitcointExchange &obj);
        ~BitcointExchange();

        
};
#endif