/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaimait <pmaimait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:49:11 by pmaimait          #+#    #+#             */
/*   Updated: 2023/12/19 14:59:09 by pmaimait         ###   ########.fr       */
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

class PmergeMe
{
    private :
    std::vector<int> _vec;
    std::deque<int> _dec;
    PmergeMe();

    public :
    PmergeMe(const PmergeMe &obj);
    PmergeMe& operator=(const PmergeMe &obj);
    ~PmergeMe();
    
    PmergeMe(std::vector<int> vec, std::deque<int> dec);
    void    sortFordJohnson(std::vector<int> vec);
    void    sortFordJohnson(std::deque<int> dec);
    int     binarySearch(std::vector<int> &vec, int value);
    int     binarySearch(std::deque<int> &deque, int value);
};

#endif
