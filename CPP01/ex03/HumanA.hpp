/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:39:26 by everonel          #+#    #+#             */
/*   Updated: 2023/09/22 02:55:45 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA{
    public:
        HumanA(std::string name, Weapon& weapon);
        ~HumanA();
        void    attack();
    private:
        std::string _name;
        Weapon&     _weapon;
};

#endif