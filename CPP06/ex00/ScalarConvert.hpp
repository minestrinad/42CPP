/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvert.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:28:55 by everonel          #+#    #+#             */
/*   Updated: 2024/01/31 21:21:08 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERT_HPP
# define SCALARCONVERT_HPP

#include <iostream>
#include <string>
#include <sstream>

class ScalarConvert {
    public: 
        ScalarConvert( );
        ScalarConvert( const ScalarConvert & );
        ~ScalarConvert( );

        ScalarConvert &operator=( const ScalarConvert & );


        template <typename T>
        static T convert(const std::string &str) {
            T   scalarValue;

            std::istringstream iss(str);                        //da fare con lo static cast
            try {
                if (!(iss >> scalarValue)) {
                    throw std::invalid_argument("Failed to convert string to T");
                }
                return scalarValue;
            }
            catch (std::exception &e) {
                std::cout << e.what() << std::endl;
                return 0;
            }
        }
    private:
};

#endif