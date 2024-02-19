/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 20:35:08 by everonel          #+#    #+#             */
/*   Updated: 2024/02/19 20:39:58 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe( ) : _size(0), _listTime(0), _vectorTime(0) { }

PmergeMe::PmergeMe( const PmergeMe &src ) { *this = src; }

PmergeMe::~PmergeMe() { }

PmergeMe &PmergeMe::operator=( const PmergeMe &src ) {
    if (this != &src) {
        _size = src._size;
        _list = src._list;
        _vector = src._vector;
        _listTime = src._listTime;
        _vectorTime = src._vectorTime;
    }
    return *this;
}

int &PmergeMe::getSize() { return _size; }

std::list<int> PmergeMe::getList() { return _list; }

std::vector<int> PmergeMe::getVector() { return _vector; }

time_t PmergeMe::getListTime() { return _listTime; }

time_t PmergeMe::getVectorTime() { return _vectorTime; }

void PmergeMe::PmergeList( char **av, int size) {
    _size = size;
     _list = _fillContainer< std::list<int> >(av);
    _listTime = _sortList();
}

void PmergeMe::PmergeVector( char **av, int size) {
    _size = size;
    _vector = _fillContainer< std::vector<int> >(av);
    _vectorTime = _sortVector();
    std::cout << "sort: ";
    printVector(_vector);
}

void PmergeMe::validateInput( char **av ) {
    for (int i = 0; av[i]; i++) {
        if (std::atoi(av[i]) < 0) {
            throw std::invalid_argument("Negative numbers are not allowed");
        }
        for (int j = i + 1; av[j]; j++) {
            if (std::atoi(av[i]) == std::atoi(av[j])) {
                std::cout << "i: " << av[i] << " j: " << av[j] << std::endl;
                throw std::invalid_argument("Duplicate numbers are not allowed");
            }
        }
    }
}

template<class T> T PmergeMe::_fillContainer(char **av) {
    T newContainer;
    for (int i = 0; i < _size; i++) {
        newContainer.push_back(std::atoi(av[i]));
    }
    return newContainer;
}

time_t PmergeMe::_sortList() {
    time_t start = time(0);
    
    return time(0) - start;
}


time_t PmergeMe::_sortVector() {
    time_t start = time(0);
    
    std::vector<int>::iterator it = _vector.begin();
    std::vector<int>::iterator it2 = _vector.begin();
    it2++;
    for (; it != _vector.end() && it2 != _vector.end(); it+=2, it2+=2) {
        if (*it > *it2) {
            std::swap(*it, *it2);
        }
    }
    printVector(_vector);
    return time(0) - start;
}

void printVector(std::vector<int> &v)
{
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
};
