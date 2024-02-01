/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:38:23 by everonel          #+#    #+#             */
/*   Updated: 2024/01/31 21:26:08 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <stdint.h>
# include "Data.hpp"

class Serializer {
    public:
        static uintptr_t    serialize(Data *ptr) {
            return reinterpret_cast<uintptr_t>(ptr);
        }
        static Data *       deserialize(uintptr_t raw) {
            return reinterpret_cast<Data *>(raw);
        }
};

#endif