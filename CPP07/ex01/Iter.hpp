/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 20:48:02 by everonel          #+#    #+#             */
/*   Updated: 2024/01/31 21:33:24 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T, typename TFunc>void iter(T *arr, int arrLen,  TFunc func) {
    for (int i = 0; i < arrLen; i++) {
        func(arr[i]);
    }
}

#endif