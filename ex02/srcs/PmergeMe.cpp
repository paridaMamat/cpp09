/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaimait <pmaimait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:49:55 by pmaimait          #+#    #+#             */
/*   Updated: 2023/12/20 11:38:45 by pmaimait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

PmergeMe::PmergeMe(){isOdd = false;}
PmergeMe::PmergeMe(const PmergeMe &obj){*this = obj;}
PmergeMe &PmergeMe::operator=(const PmergeMe &obj){
    isOdd = obj.isOdd;
    pending = obj.pending;
    pairs_v = obj.pairs_v;
    pairs_d = obj.pairs_d;
    return *this;
}
PmergeMe::~PmergeMe(){}

int binarySearch(std::deque<int> &_deq, int value) {
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

int binarySearch(std::vector<int> &_vec, int value) {
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

bool	comparePairs(const t_pair &pair1, const t_pair &pair2) {
	return (pair1.a < pair2.a);
}

void    PmergeMe::sortFordJohnson(std::vector<int>& vec) {
    // Determine the number of elements to be compared
    size_t size = (vec.size() % 2 == 0) ? vec.size() : (vec.size() - 1);
    isOdd = (vec.size() % 2 != 0);
        
    for (size_t i = 0; i < size; i += 2) {
        int first = vec[i];
        int second = vec[i + 1];

        int max = (first > second) ? first : second;
        int min = (first > second) ? second : first;

        t_pair pair;
        pair.a = max;
        pair.b = min;

        pairs_v.push_back(pair);
    }
    if (isOdd)
    {
        pending = vec[vec.size() - 1]; 
    }
	std::sort(pairs_v.begin(), pairs_v.end(), comparePairs);
	vec.clear(); 

    for (size_t i = 0; i < pairs_v.size(); i++)
        vec.push_back(pairs_v[i].a);

    for (size_t i = 0; i < pairs_v.size(); i++)
        vec.insert(vec.begin() + binarySearch(vec, pairs_v[i].b), pairs_v[i].b);

    if (isOdd)
        vec.insert(vec.begin() + binarySearch(vec, pending), pending);
}

void    PmergeMe::sortFordJohnson(std::deque<int>& deq) {
    // Determine the number of elements to be compared
    size_t size = (deq.size() % 2 == 0) ? deq.size() : (deq.size() - 1);
    isOdd = (deq.size() % 2 != 0);
        
    for (size_t i = 0; i < size; i += 2) {
        int first = deq[i];
        int second = deq[i + 1];

        int max = (first > second) ? first : second;
        int min = (first > second) ? second : first;

        t_pair pair;
        pair.a = max;
        pair.b = min;

        pairs_d.push_back(pair);
    }
    if (isOdd)
    {
        pending = deq[deq.size() - 1]; 
    }
	std::sort(pairs_d.begin(), pairs_d.end(), comparePairs);
	deq.clear(); 

    for (size_t i = 0; i < pairs_d.size(); i++)
        deq.push_back(pairs_d[i].a);

    for (size_t i = 0; i < pairs_d.size(); i++)
        deq.insert(deq.begin() + binarySearch(deq, pairs_d[i].b), pairs_d[i].b);

    if (isOdd)
        deq.insert(deq.begin() + binarySearch(deq, pending), pending);
}


PmergeMe::PmergeMe(std::vector<int> vec, std::deque<int> deq)
{
    clock_t startVector = clock();
    sortFordJohnson(vec);    
    clock_t endVector = clock();
    double durationVector = static_cast<double>(endVector - startVector) / CLOCKS_PER_SEC * 1000000;

    clock_t startDeq = clock();
    sortFordJohnson(deq);
    clock_t endDeq = clock();
    double durationDeq = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000;

    std::cout << "After: ";
    for (size_t i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;
    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: " << std::fixed << std::setprecision(5) << durationVector << " us" << std::endl; 
    std::cout << "Time to process a range of " << deq.size() << " elements with std::deq: " << std::fixed << std::setprecision(5) << durationDeq << " us" << std::endl;
}