/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 20:35:08 by everonel          #+#    #+#             */
/*   Updated: 2024/03/05 17:58:34 by everonel         ###   ########.fr       */
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

//---------------------> Getters
int     PmergeMe::getSize( ) { return _size; }

std::list<int> PmergeMe::getList( ) { return _list; }

std::vector<int> PmergeMe::getVector( ) { return _vector; }


//---------------------> Static methods
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

//---------------------> Public methods
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
    std::vector<VIterator> pendVector;
    // std::vector<VIterator> mainChain;

    VIterator it = _vector.begin();
    for (int idx = 0; it != _vector.end() && idx < _size;) {
        if ( _size - idx >= depth ) {
            for (int i = 0; idx >= (depth * 2) && i < depth && it != _vector.end(); idx++, it++, i++) {
                pendVector.push_back(it);
            }
        }
        idx+=depth;
        it+=depth;
        if (idx >= _size) {
            break;
        }
    }
    std::cout << "-------------------------------------->" << std::endl;
    std::cout << "depth: " << depth << std::endl;
    for (VIterator it = _vector.begin(); it != _vector.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << "pendVector: ";
    for (VVIterator it = pendVector.begin(); it != pendVector.end(); it++) {
        std::cout << **it << " ";
    }
    std::cout << std::endl;
    if (pendVector.size() != 0)
        _BVRecursionJacobsthal( pendVector, pendVector.begin(), depth, 1, 3 );
    
    _BVRecursion( depth / 2 );
}

void    PmergeMe::_BVRecursionJacobsthal( std::vector<VIterator> pendChain, VVIterator pend, int depth, int jacobsthal, int jacobsthal2 ) {
    if (pend == pendChain.end() || jacobsthal2 > _size) {
        return;
    }
    //-----> get actual jacobsthalDiff
    int jacobsthalDiff = jacobsthal2 - jacobsthal;
    
    VVIterator nextPend;
    //-----> get next last iterator
    if (pend + (depth * jacobsthalDiff) - 1 == pendChain.end()){
        nextPend = pend + (depth * jacobsthalDiff) - 1;
    } else {
        nextPend = pendChain.end() - 1;
    }
    pend += depth;

    std::cout << " _vector: ";
    for (VIterator it = _vector.begin(); it != _vector.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;   
    for (VVIterator it = nextPend; it != pend + (depth - 1); it-=depth) {
        for (VIterator it2 = _vector.begin() + (depth -1); it2 != *nextPend; it2+=depth) {
            if (*it2 > **it) {
                std::cout << "TEST" << std::endl;
                VIterator start = it2 - (depth - 1);
                VIterator end = *it;
                VIterator middle = *it - depth;
                std::cout << "  start: " << *start << " middle: " << *middle << " end: " << *end << std::endl;
                std::rotate(start, middle, end);
                std::cout << "  vector: " << std::endl;
                for (VIterator it = _vector.begin(); it != _vector.end(); it++) {
                    std::cout << *it << " ";
                }
                break;
            }
        }
    }
    _BVRecursionJacobsthal( pendChain, nextPend + depth, depth, jacobsthal2, jacobsthal2 + (jacobsthal * 2) );
}

 // std::cout << "--------------------------------------" << std::endl;
    // std::cout << " depth: " << depth << std::endl;
    // std::cout << "jacobsthalDiff: " << jacobsthalDiff << std::endl;
    // std::cout << " pend: " << *pend << std::endl;
    // std::cout << " nextPend: " << *nextPend << std::endl; 
    // //-----> find next pend and move
    // for (; jacobsthalDiff != 0 && nextPendTemp != pend; nextPendTemp-=depth * 2, jacobsthalDiff--) {
    //     std::cout << " nextPendTemp: " << *nextPendTemp << std::endl;
    //     for (VIterator it = _vector.begin() + (depth -1); it - nextPendTemp < 0;  it+=depth) {
    //         std::cout << "TEST: " << *it << " " << *nextPendTemp << std::endl;
    //         if (*it > *nextPendTemp) {
    //             _moveChain<VIterator>(it - (depth -1), nextPendTemp, depth);
    //             if (*it <= *pend)
    //                 nextPendTemp+=depth;
    //             else
    //                 nextPendTemp-=depth;
    //         }
    //     }
    // }
    // std::cout << "vector: ";
    // for (VIterator it = _vector.begin(); it != _vector.end(); it++) {
    //     std::cout << *it << " ";
    // }
    // std::cout << std::endl;


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

template<class C, typename CIter>void    PmergeMe::_moveChain( CIter start, CIter end, int depth ) {
    std::cout << "start: " << *(start - (depth - 1)) << " middle: " << *(end - depth) << " end: " << *end << std::endl;
    std::rotate(start - (depth - 1), end - depth , end);
}

// void    PmergeMe::_BVRecursion( int depth ) {
//     if (depth < 1 ) {
//         return;
//     }

//     VIterator pend = _vector.begin() + (2 * depth) - 1;
//     _BVRecursionJacobsthal( pend, depth, 1, 3 );
//     // VIterator it = _vector.begin() + (depth * 3) - 1;
//     // for (int i = (depth * 3) - 1; i <= _size && it != _vector.end(); it+=depth * 2, i+=depth * 2) {
//     //     for (VIterator it2 = _vector.begin() + (depth -1); it2 != it;  it2+=depth) {
//     //         if (*it2 > *it) {
//     //             _moveChain<VIterator>(it2 - (depth -1), it, depth);
//     //         }
//     //     }
//     // }
//     _BVRecursion( depth / 2 );
// }