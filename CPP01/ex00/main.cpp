/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 13:31:38 by everonel          #+#    #+#             */
/*   Updated: 2023/10/27 00:20:38 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(){
    std::cout << "\33[0;32m";
    std::cout << "      ** STATIC ALLOCATION & DEALLOCATION **" << std::endl;
    randomChump("zombom");
    std::cout << "\33[0m";

    std::cout << "\33[0;33m";
    std::cout << std::endl << "     ** DYNAMIC ALLOCATION **" << std::endl;
    Zombie *zombie = newZombie("zoomby");
    zombie->announce();
    
    std::cout << "      ** DYNAMIC DEALLOCATION **" << std::endl;
    delete zombie;
    std::cout << "\33[0m";
    return 0;
}