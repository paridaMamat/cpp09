/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaimait <pmaimait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:49:55 by pmaimait          #+#    #+#             */
/*   Updated: 2023/12/19 15:01:41 by pmaimait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

PmergeMe::PmergeMe(){}
PmergeMe::PmergeMe(const PmergeMe &obj){*this = obj;}
PmergeMe &PmergeMe::operator=(const PmergeMe &obj){
    _vec = obj._vec;
    _dec = obj._dec;
    return *this;
}
PmergeMe::~PmergeMe(){}

int PmergeMe::binarySearch(std::deque<int> &_deq, int value) {
    int left = 0; 
    int right = _deq.size() - 1; 

    while (left <= right) { 
        int mid = left + (right - left) / 2; 

        if (_deq[mid] == value) 
            return mid; 

        if (_deq[mid] < value) 
            left = mid + 1; 

        else 
            right = mid - 1;
    } 

    return left; 
}

int PmergeMe::binarySearch(std::vector<int> &_vec, int value) {
    int left = 0; 
    int right = _vec.size() - 1; 

    while (left <= right) { 
        int mid = left + (right - left) / 2; 

        if (_vec[mid] == value) 
            return mid; 

        if (_vec[mid] < value) 
            left = mid + 1; 

        else 
            right = mid - 1;
    } 

    return left; 
}

PmergeMe::PmergeMe(std::vector<int> vec, std::deque<int> deq)
{
    clock_t startVector = clock();
    sortFordJohnson(vec);    
    clock_t endVector = clock(); 

    clock_t startList = clock();
    sortFordJohnson(deq);
    clock_t endList = clock();
}