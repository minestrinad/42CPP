/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:21:00 by everonel          #+#    #+#             */
/*   Updated: 2023/11/07 19:39:17 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
    private:
    
    public:
        FragTrap(std::string name);
        FragTrap(FragTrap &src);
        ~FragTrap( );

        void attack(const std::string &target);
        void highFivesGuys( );
        FragTrap &operator=( FragTrap &);
};

#endif