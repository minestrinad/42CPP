/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 13:31:38 by everonel          #+#    #+#             */
/*   Updated: 2023/09/21 02:44:55 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(){
    std::cout << "        Zombie Constructor" << std::endl;
    Zombie zombie1("Zombert");
    zombie1.announce();
    std::cout << "    --------------------------" << std::endl;
    std::cout << "        newZombie('Zoomby')" << std::endl;
    Zombie *zombie = newZombie("Zoomby");
    zombie->announce();
    std::cout << "   ----------------------------" << std::endl;
    std::cout << "randomChump()" << std::endl;
    randomChump("Zombom");
    std::cout << "   ----------------------------" << std::endl;
    std::cout << "delete zombie" << std::endl;
    delete zombie;
    return 0;
}