/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:04:48 by everonel          #+#    #+#             */
/*   Updated: 2024/02/08 16:51:36 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConvert.hpp"
# include <fstream>

int main ( int ac, char **av ) {
    //Succesfull conversions
    if (ac != 2) {
        std::cout << "Usage: ./convert [value]" << std::endl;
        return 1;
    }
    try {
        std::cout << "________ "<< av[1] << " ________" << std::endl;
        ScalarConvert::convert(av[1]);
        std::cout << "______________________" << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}