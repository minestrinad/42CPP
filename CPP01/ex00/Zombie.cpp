/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 13:30:17 by everonel          #+#    #+#             */
/*   Updated: 2023/09/21 02:08:04 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    this->_name = name;
    return ;
}

Zombie::~Zombie(void)
{
    std::cout << "Zombie " << this->_name << " has died" << std::endl;
    return ;
}

void	Zombie::announce(void)
{
    std::cout << this->_name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
    return ;
}