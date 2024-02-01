/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:53:12 by everonel          #+#    #+#             */
/*   Updated: 2024/01/31 13:02:58 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    uintptr_t raw;
    Data *data = new Data;
    Data *data2 = new Data;

    data->s1 = "Hello";
    data->n = 42;
    data->s2 = "World";
    std::cout << "data: " << *data << std::endl;

    raw = Serializer::serialize(data);
    std::cout << "raw of data: " << raw << std::endl;
    std::cout << "data2 pre raw deserialization: " << *data2 << std::endl;
    data2 = Serializer::deserialize(raw);
    std::cout << "data2 post raw deserialization: " << *data2 << std::endl;
    delete data;
    return (0);
}