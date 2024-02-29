/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 20:35:08 by everonel          #+#    #+#             */
/*   Updated: 2024/02/29 04:23:01 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe( int size, char **av ) : _size(size), _maxDepth(0) { 
    for (int i = 0; i < _size; i++) {
        _vector.push_back(std::atoi(av[i]));
    }
    _list.assign(_vector.begin(), _vector.end());
}

PmergeMe::PmergeMe( const PmergeMe &src ) { *this = src; }

PmergeMe::~PmergeMe( ) { }

PmergeMe &PmergeMe::operator=( const PmergeMe &src ) {
    if (this != &src) {
        _size = src._size;
        _list = src._list;
        _vector = src._vector;
        _maxDepth = src._maxDepth;
    }
    return *this;
}

int     PmergeMe::getSize() { return _size; }

std::list<int> PmergeMe::getList() { return _list; }

std::vector<int> PmergeMe::getVector() { return _vector; }


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



double PmergeMe::PmergeVector( ) {
    clock_t start, end;
    start = clock();

    _PVRecursion( 1 );
    _BVRecursion( _maxDepth );
    
    end = clock();
    return ((double) (end - start)) / CLOCKS_PER_SEC * 1e6;
}

void    PmergeMe::_PVRecursion( int depth ) {
    if (depth > _size / 2) {
        _maxDepth = depth / 2;
        return;
    }
    VIterator it = _vector.begin() + (depth - 1);
    VIterator it2 = _vector.begin() + (depth * 2) - 1;
    for (int i = depth *2; i <= _size; it+=depth * 2, it2+=depth * 2, i+=depth * 2) {
        if (*it > *it2) {
            _swapChain<VIterator>(it, it2, depth);
        }
    }
    _PVRecursion( depth * 2 );
}

void    PmergeMe::_BVRecursion( int depth ) {
    if (depth < 1 ) {
        return;
    }

    VIterator pend = _vector.begin() + (2 * depth) - 1;
    _BVRecursionJacobsthal( pend, depth, 1, 3 );
    // VIterator it = _vector.begin() + (depth * 3) - 1;
    // for (int i = (depth * 3) - 1; i <= _size && it != _vector.end(); it+=depth * 2, i+=depth * 2) {
    //     for (VIterator it2 = _vector.begin() + (depth -1); it2 != it;  it2+=depth) {
    //         if (*it2 > *it) {
    //             _moveChain<VIterator>(it2 - (depth -1), it, depth);
    //         }
    //     }
    // }
    _BVRecursion( depth / 2 );
}

void    PmergeMe::_BVRecursionJacobsthal( VIterator pend, int depth, int jacobsthal, int jacobsthal2 ) {
    if (pend == _vector.end() || jacobsthal2 > _size) {
        return;
    }
    std::cout << "----------------------" << std::endl;
    std::cout << "depth: " << depth << std::endl;
    //-----> get actual jacobsthalDiff
    int jacobsthalDiff = jacobsthal2 - jacobsthal;
    std::cout << "jacobsthalDiff: " << jacobsthalDiff << std::endl;

    //-----> get next last iterator
    VIterator nextPend = pend + ((depth * jacobsthalDiff * 2) - depth);
    std::cout << "nextPend: " << *nextPend << std::endl;
    if (nextPend - _vector.begin() >= _size) {
        for (; pend != _vector.end() && (pend + depth * 2) - _vector.begin() < _size; pend+=depth * 2) { }
        nextPend = pend;
    }
    std::cout << "nextPend: " << *nextPend << std::endl;

    //-----> find next pend and move
    VIterator nextPendTemp = nextPend;
    for (; jacobsthalDiff != 0 && nextPendTemp != pend; nextPendTemp-=depth * 2, jacobsthalDiff--) {
        std::cout << "jacobsthalDiff: " << jacobsthalDiff << std::endl;
        for (VIterator it = nextPendTemp; it != _vector.begin();  it-=depth) {
            if (*it > *nextPendTemp) {
                _moveChain<VIterator>(it - (depth -1), nextPendTemp, depth);
            }
        }
    }

    _BVRecursionJacobsthal( nextPend, depth / 2, jacobsthal2, jacobsthal2 + (jacobsthal * 2) );
}


double PmergeMe::PmergeList( ) {
    clock_t start, end;

    start = clock();

    // _PLRecursion( 1 );
    // _BLRecursion( _maxDepth );
    
    end = clock();
    return ((double) (end - start)) / CLOCKS_PER_SEC * 1e6;
}

template<class C, typename CIter>void    PmergeMe::_swapChain( CIter it, CIter it2, int depth ) {
    if (depth == 1) {
        std::iter_swap(it, it2);
    } else {
        for (int i = 0; i < depth; i++) {
            std::iter_swap(it - i, it2 - i);
        }
    }
}

template<class C, typename CIter>void    PmergeMe::_moveChain( CIter it, CIter it2, int depth ) {
    for (int i = 0; i < depth; i++) {
        std::rotate(it, it2, it2 + 1);
    }
}

