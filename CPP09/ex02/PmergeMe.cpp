/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 20:35:08 by everonel          #+#    #+#             */
/*   Updated: 2024/03/21 16:28:27 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe( int size ) : _size(size), _maxDepth(0) { }

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
        for (int j = 0; av[i][j]; j++) {
            if (!std::isdigit(av[i][j])) {
                throw std::invalid_argument("Only numbers are allowed");
            }
        }
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

/*__________________________________________*/
/*__________________VECTOR__________________*/
//---------------------> Public methods

double PmergeMe::PmergeVector( char **input ) {
    clock_t start, end;
    start = clock();
    
    for (int i = 0; i < _size; i++) {
        _vector.push_back(std::atoi(input[i]));
    }
    
    _PVRecursion( 1 );
    _BVRecursion( _maxDepth );
    
    end = clock();
    return static_cast<double>(end - start) / CLOCKS_PER_SEC;
}

//---------------------> Private methods

void    PmergeMe::_PVRecursion( int depth ) {
    if (depth > _size / 2) {
        _maxDepth = depth / 2;
        return;
    }
    
    VIterator it = _vector.begin() + depth - 1;
    VIterator it2 = _vector.begin() + depth * 2 - 1;

    for (int i = depth *2; i <= _size; it+=depth * 2, it2+=depth * 2, i+=depth * 2) {
        if (*it > *it2) {
            _VSwapChain(it, it2, depth);
        }
    }
    
    _PVRecursion( depth * 2 );
}

void    PmergeMe::_BVRecursion( int depth ) {
    if ( depth < 1 ) { return; }

    if ( _pendVector.size() != 0 ) { _pendVector.clear(); }

    for (int idx = (depth * 3) -1; idx < _size; idx+=depth * 2) {
        _pendVector.push_back(_vector.begin() + idx);
    }
    if (_pendVector.size() != 0) {
        //-----> populate jacobsthalChain
        std::vector<VIterator> jacobsthalChain;
        VVIterator end = (_pendVector.size() < 2) ? _pendVector.end() : _pendVector.begin() + 2;
        std::copy(_pendVector.begin(), end, std::back_inserter(jacobsthalChain));

        //-----> call jacobsthal recursion
        _BVRecursionJacobsthal(jacobsthalChain, 0, depth, 1, 3 );
    }
    _BVRecursion( depth / 2 );
}

void    PmergeMe::_BVRecursionJacobsthal( std::vector<VIterator> pendChain, int pendIdx, int depth, int jacobsthal, int jacobsthal2 ) {

    int jacobsthalDiff = jacobsthal2 - jacobsthal;
    int count = 0;
    for (VVIterator it = pendChain.end() -1; count < jacobsthalDiff; count++, it--) {
        for (VIterator it2 = _vector.begin() + (depth -1); it2 != *it; it2+=depth) {
            if (*it2 > **it) {
                _VMoveChain(it2, *it, depth);
                for (VVIterator it3 = pendChain.begin(); it3 != it; it3++) { if (**it3 > *it2) { *it3 += depth; } }
                break ;
            }
        }
        pendChain.pop_back();
        if (it == pendChain.begin()) { break; }
    }
    pendIdx += jacobsthalDiff;

    if (pendIdx < (int)_pendVector.size()) {
        int nextJacobsthalDiff = (jacobsthal2 + jacobsthal * 2) - jacobsthal2;
        for (int i = 0; i < nextJacobsthalDiff && pendIdx + i < (int)_pendVector.size(); i++) {
            pendChain.push_back(_pendVector[pendIdx + i]);
        }

        _BVRecursionJacobsthal( pendChain, pendIdx, depth, jacobsthal2, jacobsthal2 + (jacobsthal * 2) );
    }
}

void    PmergeMe::_VSwapChain( VIterator it, VIterator it2, int depth ) {
    for (int i = 0; i < depth; i++) {
        std::iter_swap(it - i, it2 - i);
    }
}

void    PmergeMe::_VMoveChain( VIterator posIt, VIterator pendIt, int depth ) { 
    std::rotate(posIt - (depth - 1), (pendIt + 1) - depth, pendIt + 1);
}


/*__________________________________________*/
/*___________________LIST___________________*/
//---------------------> Public methods

double PmergeMe::PmergeList( char **input ) {
    clock_t start, end;

    start = clock();

    for (int i = 0; i < _size; i++) {
        _list.push_back(std::atoi(input[i]));
    }
    
    _PLRecursion( 1 );
    _BLRecursion( _maxDepth );
    
    end = clock();
    return static_cast<double>(end - start) / CLOCKS_PER_SEC;
}

//---------------------> Private methods

void    PmergeMe::_PLRecursion( int depth ) {
    if (depth > _size / 2) {
        _maxDepth = depth / 2;
        return;
    }
    LIterator it = _list.begin();
    LIterator it2 = _list.begin();
    std::advance(it, depth - 1);
    std::advance(it2, depth * 2 - 1);
    for (int i = depth * 2; i <= _size; std::advance(it, depth * 2), std::advance(it2, depth * 2), i+=depth * 2) {
        if (*it > *it2) {
            _LSwapChain(it, it2, depth);
        }
    }
    _PLRecursion( depth * 2 );
}

void    PmergeMe::_BLRecursion( int depth ) {
    if ( depth < 1 ) { return; }

    if ( _pendList.size() != 0 ) { _pendList.clear(); }

    for (int idx = (depth * 3) -1; idx < _size; idx+=depth * 2) {
        LIterator it = _list.begin();
        std::advance(it, idx);
        _pendList.push_back(it);
    }

    if (_pendList.size() != 0) {
        std::list<LIterator> jacobsthalChain;

        LLIterator end;
        if (_pendList.size() < 2) { 
            end = _pendList.end();
        } else {
            end = _pendList.begin();
            std::advance(end, 2);
        }
        std::copy(_pendList.begin(), end, std::back_inserter(jacobsthalChain));

        _BLRecursionJacobsthal(jacobsthalChain, 0, depth, 1, 3 );
    }
    _BLRecursion( depth / 2 );
}

void    PmergeMe::_BLRecursionJacobsthal( std::list<LIterator> pendChain, int pendIdx, int depth, int jacobsthal, int jacobsthal2 ) {

    int jacobsthalDiff = jacobsthal2 - jacobsthal;
    int count = 0;
    LLIterator it = pendChain.end();
    it--;
    for (;count < jacobsthalDiff; count++) {
        LIterator it2 = _list.begin();

        for (std::advance(it2, depth - 1); *it2 != **it; std::advance(it2, depth)) {
            if (*it2 > **it) {
                _LMoveChain(it2, *it, depth);
                for (LLIterator it3 = pendChain.begin(); it3 != it; std::advance(it3, 1)) { if (**it3 > *it2) { std::advance(*it3, depth); } }
                break ;
            }
        }
        if (it == pendChain.begin()) { break; }
        --it;
        pendChain.pop_back();
    }
    pendIdx += jacobsthalDiff;

    if (pendIdx < (int)_pendList.size()) {
        int nextJacobsthalDiff = (jacobsthal2 + jacobsthal * 2) - jacobsthal2;
        for (int i = 0; i < nextJacobsthalDiff && pendIdx + i < (int)_pendList.size(); i++) {
            LLIterator it = _pendList.begin();
            std::advance(it, pendIdx + i);
            pendChain.push_back(*it);
        }

        _BLRecursionJacobsthal( pendChain, pendIdx, depth, jacobsthal2, jacobsthal2 + (jacobsthal * 2) );
    }
}

void    PmergeMe::_LSwapChain( LIterator it, LIterator it2, int depth ) {
    for (int i = 0; i < depth; i++) {
        LIterator it3 = it;
        LIterator it4 = it2;
        std::advance(it3, (i * -1));
        std::advance(it4, (i * -1));
        std::iter_swap(it3, it4);
    }
}

void    PmergeMe::_LMoveChain( LIterator posIt, LIterator pendIt, int depth ) { 
    // std::rotate(posIt - (depth - 1), (pendIt + 1) - depth, pendIt + 1);
    LIterator start = posIt;
    std::advance(start, (depth - 1) * -1);
    LIterator middle = pendIt;
    std::advance(middle, (depth - 1) * -1);
    LIterator end = pendIt;
    std::advance(end, 1);
    std::rotate(start, middle, end);
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