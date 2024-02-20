/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 20:35:08 by everonel          #+#    #+#             */
/*   Updated: 2024/02/20 01:33:42 by everonel         ###   ########.fr       */
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
}

void PmergeMe::validateInput( char **av ) {
    for (int i = 0; av[i]; i++) {
        if (std::atoi(av[i]) < 0) {
            throw std::invalid_argument("Negative numbers are not allowed");
        }
        for (int j = i + 1; av[j]; j++) {
            if (std::atoi(av[i]) == std::atoi(av[j])) {
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
    
    //************** 1. Sort Pairwise **************
    {
        std::vector<int>::iterator it = _vector.begin();
        std::vector<int>::iterator it2 = _vector.begin() + 1;
        for (; it != _vector.end() && it2 != _vector.end(); it+=2, it2+=2) {
            if (*it > *it2) {
                std::swap(*it, *it2);
            }
        }
        std::cout << "After Pairwise: ";
        for (std::vector<int>::iterator it = _vector.begin(); it != _vector.end(); it++) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
    //************** 2. Recursive Sort by Highest in pair **************
    {
        std::vector<int>::iterator it = _vector.begin() + 1;
        std::vector<int>::iterator it2 = _vector.begin() + 3;
        for (;it - 1 != _vector.end() && it != _vector.end(); it+=2) {
            it2 = it + 2;
            for (; it2 != _vector.end(); it2+=2) {
                if (*it > *it2) {
                    std::swap(*it, *it2);
                    std::swap(*(it - 1), *(it2 - 1));
                }
            }
        }
        std::cout << "After Merge: ";
        for (std::vector<int>::iterator it = _vector.begin(); it != _vector.end(); it++) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
    //************** 3. Insert Pends **************
    {
        int insertionCount = 0;
        std::vector<int>::iterator it = _vector.begin();
        std::vector<int>::iterator it2 = _vector.begin() + 2;
        int i = 0;
        for (; i < _size && it != _vector.end() && it2 != _vector.end(); i+=2) {
            if (*it2 < *it && *it2 > *(it - 1)) {
                _vector.insert(it, *it2);
                _vector.erase(_vector.begin() + i);
                insertionCount++;
                it = _vector.begin() + insertionCount;
                it2 = _vector.begin() + 2 * insertionCount + insertionCount;
                i = insertionCount + 2;
            }
            else if (*it2 > *it) {
                if (*it2 < *(it + 1)) {
                    _vector.insert(it + 1, *it2);
                }
                else {
                    _vector.insert(it + 2, *it2);
                }
                _vector.erase(_vector.begin() + i);
                insertionCount++;
                it = _vector.begin() + insertionCount;
                it2 = _vector.begin() + 2 * insertionCount + insertionCount;
                i = insertionCount + 2;
            }
            else {
                it += 2;
                it2 += 2;
            }
        }
    }
    
    return time(0) - start;
}




