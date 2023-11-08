/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:07:39 by everonel          #+#    #+#             */
/*   Updated: 2023/11/07 19:38:48 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
    private:
    
    public:
        ScavTrap(std::string name);
        ScavTrap(ScavTrap &src);
        ~ScavTrap( );

        void attack(const std::string &target);
        void guardGate();
        ScavTrap &operator=( ScavTrap &);
};

#endif