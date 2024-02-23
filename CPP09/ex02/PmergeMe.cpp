/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 20:35:08 by everonel          #+#    #+#             */
/*   Updated: 2024/02/23 13:59:58 by everonel         ###   ########.fr       */
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

void    PmergeMe::_swapChain( std::vector<int>::iterator it, std::vector<int>::iterator it2, int depth ) {
    if (depth == 1) {
        std::iter_swap(it, it2);
    } else {
        std::cout << "Swapping: " << *it << " with " << *it2 << std::endl;
        for (int i = 0; i < depth; i++) {
            std::iter_swap(it - i, it2 - i);
        }
    }
}

void    PmergeMe::_predecessorRecursion( int *depth ) {
    if (*depth > _size / 2) {
        return;
    }

    
        std::vector<int>::iterator it = _vector.begin() + *depth -1;
        std::vector<int>::iterator it2 = _vector.begin() + (*depth * 2) -1;
        for (; it != _vector.end() && it2 != _vector.end(); it+=*depth + 1, it2+=*depth + 1) {
            if (*it > *it2) {
                _swapChain(it, it2, *depth);
            }
        }
        std::cout << "After Pairwise: ";
        for (std::vector<int>::iterator it = _vector.begin(); it != _vector.end(); it++) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    
    int newDepth = *depth * 2;
    std::cout << "New Depth: " << newDepth << std::endl;
    _predecessorRecursion( &newDepth );
}

void    PmergeMe::_moveChain( std::vector<int>::iterator it, std::vector<int>::iterator it2, int depth ) {
    (void)depth;
    std::cout << "Moving: " << *it << " to " << *it2 << std::endl;
}


void    PmergeMe::_binaryRecursion( int *depth ) {
    if (*depth > 0 ) {
        return;
    }

    {
        std::vector<int>::iterator it = _vector.begin() + *depth * 2;
        std::vector<int>::iterator it2 = _vector.begin() + *depth * 2;
        for (; it != _vector.end() && it2 != _vector.end(); it+=*depth, it2+=*depth) {
            if (_vector.begin() > it) {
                _moveChain(it, it2, *depth);
                continue;
            }
            for (;it2 != _vector.begin() && *it > *it2; it2-=*depth);
            if (it2 != _vector.begin()) {
                _swapChain(it, it2, *depth);
            }
            it2 = it;
        }
        std::cout << "After Pairwise: ";
        for (std::vector<int>::iterator it = _vector.begin(); it != _vector.end(); it++) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
    int newDepth = *depth / 2;
    _binaryRecursion( &newDepth );
}

time_t PmergeMe::_sortVector() {
    time_t start = time(0);
    int depth = 1;
    _predecessorRecursion( &depth );
    _binaryRecursion( &depth );
    
    return time(0) - start;
}




