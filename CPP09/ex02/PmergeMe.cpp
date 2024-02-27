/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 20:35:08 by everonel          #+#    #+#             */
/*   Updated: 2024/02/27 21:58:49 by everonel         ###   ########.fr       */
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

double PmergeMe::getVectorTime() { return _vectorTime; }

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
        for (int i = 0; i < depth; i++) {
            std::iter_swap(it - i, it2 - i);
        }
    }
}

void    PmergeMe::_predecessorRecursion( int depth ) {
    if (depth > _size / 2) {
        _depth = depth / 2;
        return;
    }
    std::vector<int>::iterator it = _vector.begin() + (depth - 1);
    std::vector<int>::iterator it2 = _vector.begin() + (depth * 2) - 1;
    for (int i = depth *2; i <= _size; it+=depth * 2, it2+=depth * 2, i+=depth * 2) {
        if (*it > *it2) {
            _swapChain(it, it2, depth);
        }
    }
    _predecessorRecursion( depth * 2 );
}

void    PmergeMe::_moveChain( std::vector<int>::iterator it, std::vector<int>::iterator it2, int depth ) {
    std::cout << "Moving chain " << *it << " " << *it2 << std::endl;
    for (int i = 0; i < depth; i++) {
        std::rotate(it, it2, it2 + 1);
    }
}

void    PmergeMe::_binaryRecursion( int depth ) {
    if (depth < 1 ) {
        return;
    }
    std::vector<int>::iterator it = _vector.begin() + (depth * 3) - 1;
    for (int i = (depth * 3) - 1; i <= _size - depth; it+=depth * 2, i+=depth * 2) {
        std::vector<int>::iterator it2 = _vector.begin() + (depth -1);
        for (int j = 0; j <= i;  it2+=depth, j+=depth) {
            if (*it2 > *it) {
                _moveChain(it2 - (depth -1), it, depth);
            }
        }
    }
    _binaryRecursion( depth / 2 );
}

double PmergeMe::_sortVector() {
    clock_t start, end;

    start = clock();
    _predecessorRecursion( 1 );
    std::cout << "Depth: " << _depth << std::endl;
    _binaryRecursion( _depth );
    // if ( _vector[_size] < _vector[_size - 1]) {
    //     for (std::vector<int>::iterator it = _vector.begin(); it != _vector.end(); it++) {
    //         if (_vector[_size] < *it) {
    //             _moveChain(it, _vector.end(), 1);
    //             break;
    //         }
    //     }
    // }
    end = clock();
    double timeElapsed = ((double) (end - start)) / CLOCKS_PER_SEC * 1e6;
    return timeElapsed;
}

// double PmergeMe::_getCurrentTimeMicroS() {
//     struct timeval tv;
//     gettimeofday(&tv, NULL);
//     return (double)tv.tv_sec * 1e6 + (double)tv.tv_usec;
// }



