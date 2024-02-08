/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvert.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:28:55 by everonel          #+#    #+#             */
/*   Updated: 2024/02/08 20:33:08 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERT_HPP
# define SCALARCONVERT_HPP

#include <iostream>
#include <string>
#include <sstream>
# include <limits>
# include <iomanip>

class ScalarConvert {
    public: 
        static void     convert( const std::string & );
        
    private:
        ScalarConvert( );
        ScalarConvert( const ScalarConvert & );
        ~ScalarConvert( );

        ScalarConvert &operator=( const ScalarConvert & );
        static  void    _printImpossible( );
        static  bool    _specialCase(const std::string &literal);
        static  void    _tryConvertToNumeric( const std::string & );
        static  void    _printNumeric( int , float , double );
        static  void    _tryPrintChar( char );
};

#endif