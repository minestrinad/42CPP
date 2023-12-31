/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:39:26 by everonel          #+#    #+#             */
/*   Updated: 2023/10/27 00:47:28 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB{
    public:
        HumanB();
        HumanB(std::string name);
        ~HumanB();
        
        void    setWeapon(Weapon& weapon);
        void    attack();
    private:
        std::string _name;
        Weapon*     _weapon;
};

#endif