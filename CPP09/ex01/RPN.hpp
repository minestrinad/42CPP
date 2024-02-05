/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:58:18 by everonel          #+#    #+#             */
/*   Updated: 2024/02/03 17:27:44 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <sstream>
#include <stack>


/*              RPN                     */
float   solveRPN( const std::string& );

/*              UTILS                   */
float   tryParseInt( std::string src );
bool    isOperator(const std::string& );
float   calculate( float a, float b, char op );

#endif