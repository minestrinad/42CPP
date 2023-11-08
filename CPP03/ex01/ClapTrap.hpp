/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:59:07 by everonel          #+#    #+#             */
/*   Updated: 2023/11/07 19:36:46 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

# define RESET      "\033[0m"
# define DEBUG		"\033[33m"
# define DAMAGE		"\033[31m"
# define CURE       "\033[32m"

class ClapTrap
{
    public:
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap &src);
        ~ClapTrap();

        void attack(std::string const & target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        
        ClapTrap &operator=(const ClapTrap &src);
    
    protected:
        std::string _name;
        int         _hitPoints;
        int         _energyPoints;
        int         _attackDamage;
};


#endif