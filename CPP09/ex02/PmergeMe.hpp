/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 23:22:57 by everonel          #+#    #+#             */
/*   Updated: 2024/03/03 11:25:39 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <list>
# include <vector>
# include <time.h>
# include <algorithm>
# include <sys/time.h>
# include <limits>
# include <iomanip>

# define TIME_RESOLUTION 100000

class PmergeMe
{
    typedef std::list<int>::iterator    LIterator;
    typedef std::vector<int>::iterator  VIterator;
    private:
        int                 _size;
        std::list<int>      _list;
        std::vector<int>    _vector;
        int                 _maxDepth;
        
        void    _PVRecursion( int );
        void    _BVRecursion( int );
        void    _BVRecursionJacobsthal( VIterator, int, int, int );

        void    _PLRecursion( int );
        void    _BLRecursion( int );
        
        template <class C, typename CIter>void    _swapChain( CIter, CIter, int);
        template <class C, typename CIter>void    _insertChain( CIter, CIter, int);
        // double  _jacobsthalRecursion( int );
    public:
        PmergeMe( int, char ** );
        PmergeMe( const PmergeMe &src );
        ~PmergeMe( );
        
        PmergeMe &operator=( const PmergeMe &src );

        int                  getSize( );
        std::list<int>       getList( );
        std::vector<int>     getVector( );

        static void     validateInput( char ** );
        double          PmergeList ( );
        double          PmergeVector( );
};

#endif