/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:51:28 by everonel          #+#    #+#             */
/*   Updated: 2024/01/31 13:03:44 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>

struct Data {
    std::string s1;
    int n;
    std::string s2;
};

std::ostream &operator<<(std::ostream &o, Data const &i){
    o << "s1: " << i.s1 << std::endl;
    o << "n: " << i.n << std::endl;
    o << "s2: " << i.s2 << std::endl;
    return o;
}

#endif