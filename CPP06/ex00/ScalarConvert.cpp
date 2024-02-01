/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvert.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:40:54 by everonel          #+#    #+#             */
/*   Updated: 2024/01/31 12:13:23 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConvert.hpp"

ScalarConvert::ScalarConvert() { }

ScalarConvert::ScalarConvert( ScalarConvert const & src ) { *this = src; }

ScalarConvert::~ScalarConvert() { }

ScalarConvert &	ScalarConvert::operator=( ScalarConvert const & rhs )
{
    (void)rhs;
    return *this;
}
