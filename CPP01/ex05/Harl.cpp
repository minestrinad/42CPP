/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 00:53:27 by everonel          #+#    #+#             */
/*   Updated: 2023/10/27 00:59:39 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() { }

Harl::~Harl() { }

void    Harl::complain( std::string level ) {
    void    (Harl::*fArray[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string sArray[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int i = 0;
    while (sArray[i] != level)
        i++;
    if (i < 4)
        (this->*fArray[i])();      // perchè ??
}

void    Harl::debug(void) {
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl;
    std::cout << "I really do!" << std::endl;
}

void    Harl::info(void) {
    std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
    std::cout << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void    Harl::warning(void) {
    std::cout << "I think I deserve to have some extra bacon for free." << std::endl; 
    std::cout << "I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void    Harl::error(void) {
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
