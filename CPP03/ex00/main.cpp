/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:59:15 by everonel          #+#    #+#             */
/*   Updated: 2023/11/07 18:59:17 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap clap("Clap");
    ClapTrap trap("Trap");
    for (int i = 0; i <= 10; i++)
    {
        clap.attack("Trap");
        trap.takeDamage(2);
        trap.beRepaired(1);
    }
    return 0;
}
