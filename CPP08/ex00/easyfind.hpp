/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 00:05:15 by everonel          #+#    #+#             */
/*   Updated: 2024/02/01 00:54:49 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <vector>
# include <exception>
# include <iterator>

template<typename T>int easyfind(T intContainer, int occ) {
    try {
        typename T::iterator iter;
        for (iter = intContainer.begin(); iter < intContainer.end(); iter++){
            if (*iter == occ ) {
                return *iter;
            }
        }
        throw std::exception();
        return 0;
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}

#endif