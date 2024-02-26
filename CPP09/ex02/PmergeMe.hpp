/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 23:22:57 by everonel          #+#    #+#             */
/*   Updated: 2024/02/25 19:18:44 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <list>
# include <vector>
# include <exception>
# include <time.h>
# include <algorithm>

# include <limits>


class PmergeMe
{
    private:
        int                 _size;
        std::list<int>      _list;
        std::vector<int>    _vector;
        time_t              _listTime;
        time_t              _vectorTime;
        int                 _depth;

        template<class T> T    _fillContainer(char **);
        time_t  _sortList();
        time_t  _sortVector();
        void    _predecessorRecursion( int );
        void    _binaryRecursion( int );
        void    _swapChain( std::vector<int>::iterator, std::vector<int>::iterator, int);
        void    _moveChain( std::vector<int>::iterator, std::vector<int>::iterator, int);
    public:
        PmergeMe( );
        PmergeMe( const PmergeMe &src );
        PmergeMe &operator=( const PmergeMe &src );
        ~PmergeMe();

        int                  &getSize();
        std::list<int>       getList();
        std::vector<int>     getVector();
        time_t               getListTime();
        time_t               getVectorTime();

        static void validateInput( char ** );
        void PmergeList( char **, int );
        void PmergeVector( char **, int );
};


#endif