/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:58:50 by everonel          #+#    #+#             */
/*   Updated: 2024/01/31 20:33:16 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTION_HPP
# define FUNCTION_HPP

# include <iostream>

template <class T_val>void    swap(T_val &val1, T_val &val2) {
    T_val tmp = val1;
    val1 = val2;
    val2 = tmp;
}

template <class T_val>T_val   min(T_val val1, T_val val2) {
    return (val1 < val2) ? val1 : val2;
}

template <class T_val>T_val   max(T_val val1, T_val val2) {
    return (val1 < val2) ? val2 : val1;
}

#endif