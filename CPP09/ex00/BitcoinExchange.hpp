/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:42:26 by everonel          #+#    #+#             */
/*   Updated: 2024/02/19 12:23:26 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <fstream>
# include <map>
# include <sstream>
# include <iomanip>
# include <algorithm>
# include <cmath>
# include <cfloat>


# define DATABASE "data.csv"
# define DATE_SIZE 10


class BitcoinExchanger {
    private:
        std::map<int, float>    _dataMap;

        void        _loadData( );
        float       _validateQuery( const std::string& );
        void        _validateDate( const std::string& );
        int         _findClosestDate(const std::string& );
        int         _str2time( const std::string& );
        
        float   _tryParseFloat(const std::string& );
    public:
        BitcoinExchanger( );
        BitcoinExchanger( const BitcoinExchanger& );
        BitcoinExchanger &operator=( const BitcoinExchanger& );
        ~BitcoinExchanger( );

        float   answerQuery( const std::string& );
};

#endif