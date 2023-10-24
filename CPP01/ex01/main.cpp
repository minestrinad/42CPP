/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 13:31:38 by everonel          #+#    #+#             */
/*   Updated: 2023/09/21 17:01:07 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(){
    Zombie *zombie = zombieHorde(5, "Zom_bye");
    for (int i = 0; i < 5; i++)
    {
        zombie[i].announce();
    }
    delete[] zombie;
    return 0;
}