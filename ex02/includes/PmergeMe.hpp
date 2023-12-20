/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaimait <pmaimait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:49:11 by pmaimait          #+#    #+#             */
/*   Updated: 2023/12/20 11:34:28 by pmaimait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
#include <ctime>
#include<limits.h>
#include <cctype> // For isdigit function
#include <cstdlib> // For atoi function
#include<iomanip> // For setprecision

typedef struct s_pair {
    int a;
    int b;
}t_pair;

class PmergeMe
{
    private :
    std::vector<t_pair>	pairs_v;
    std::deque<t_pair>	pairs_d;
    bool isOdd;
    int  pending;
    PmergeMe();

    public :
    PmergeMe(const PmergeMe &obj);
    PmergeMe& operator=(const PmergeMe &obj);
    ~PmergeMe();
    
    PmergeMe(std::vector<int> vec, std::deque<int> dec);
    void    sortFordJohnson(std::vector<int>& vec);
    void    sortFordJohnson(std::deque<int>& dec);
};

#endif
