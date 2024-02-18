/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 23:22:57 by everonel          #+#    #+#             */
/*   Updated: 2024/02/11 17:48:02 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <exception>
#include <time.h>
#include <algorithm>


class PmergeMe
{
    private:
        static int                 _size;
        static std::list<int>      _list;
        static std::vector<int>    _vector;
        static time_t              _listTime;
        static time_t              _vectorTime;

        PmergeMe( );
        template<class T>static T    _fillContainer(char **);
        static time_t  _sortList();
        static time_t  _sortVector();
    public:
        PmergeMe( const PmergeMe &src );
        PmergeMe &operator=( const PmergeMe &src );
        ~PmergeMe();

        static int                  getSize();
        static std::list<int>       getList();
        static std::vector<int>     getVector();
        static time_t               getListTime();
        static time_t               getVectorTime();

        static void validateInput( char ** );
        static void PmergeList( char ** );
        static void PmergeVector( char ** );
};

#endif