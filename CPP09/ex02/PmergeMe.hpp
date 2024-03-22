/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 23:22:57 by everonel          #+#    #+#             */
/*   Updated: 2024/03/21 15:18:09 by everonel         ###   ########.fr       */
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

# define TIME_RESOLUTION 1000

typedef std::list<int>::iterator            LIterator;
typedef std::vector<int>::iterator          VIterator;

typedef std::vector<VIterator>::iterator    VVIterator;
typedef std::list<LIterator>::iterator      LLIterator;


class PmergeMe
{
    public:
        PmergeMe( int );
        PmergeMe( const PmergeMe &src );
        ~PmergeMe( );
        
        PmergeMe &operator=( const PmergeMe &src );

        int                  getSize( );
        std::list<int>       getList( );
        std::vector<int>     getVector( );

        static void     validateInput( char ** );
        
        double          PmergeList ( char ** );
        double          PmergeVector( char ** );
    
    private:
        int                     _size;
        int                     _maxDepth;
        
        /*__________________________________________*/
        /*___________________VECTOR_________________*/

        std::vector<int>        _vector;
        std::vector<VIterator>  _pendVector;
        
        void    _PVRecursion( int );
        void    _BVRecursion( int );
        void    _BVRecursionJacobsthal( std::vector<VIterator>, int, int, int, int );
        
        void    _VSwapChain( VIterator, VIterator, int);
        void    _VMoveChain( VIterator, VIterator, int);

        /*__________________________________________*/
        /*___________________LIST___________________*/
        
        std::list<int>          _list;
        std::list<LIterator>    _pendList;

        void    _PLRecursion( int );
        void    _BLRecursion( int );
        void    _BLRecursionJacobsthal( std::list<LIterator>, int, int, int, int );

        void    _LSwapChain( LIterator, LIterator, int);
        void    _LMoveChain( LIterator, LIterator, int);
};

#endif