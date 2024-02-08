/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 20:48:02 by everonel          #+#    #+#             */
/*   Updated: 2024/02/08 20:47:26 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T, typename TFunc>void iter(T *ptr, int ptrSize,  TFunc func) {
    if (!ptr) {
        return;
    }
    for (int i = 0; i < ptrSize; i++) {
        func(ptr[i]);
    }
}

#endif