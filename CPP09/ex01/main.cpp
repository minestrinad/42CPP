/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 22:42:08 by everonel          #+#    #+#             */
/*   Updated: 2024/02/03 17:26:25 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main (int ac, char **av) 
{
    if (ac != 2)
        return std::cout << "Usage: ./rnp <expression>", 1;
        
    try {
        
        std::stack<float> numberStack;
        int res = solveRPN(av[1]);
        std::cout << res << std::endl;

    } catch( std::invalid_argument &ex) {
        std::cout << "Invalid argument: " << ex.what() << std::endl;
    } catch( std::logic_error &ex) {
        std::cout << "Logic error: " << ex.what() << std::endl;
    } catch( std::runtime_error &ex) {
        std::cout << "Runtime error: " << ex.what() << std::endl;
    }
}
