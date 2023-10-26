/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:12:05 by everonel          #+#    #+#             */
/*   Updated: 2023/10/27 00:48:58 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

# include <iostream>

class Weapon{
    public:
        Weapon();
        Weapon(std::string type);
        ~Weapon();
        
        void    setType(std::string type);
        const   std::string &getType();
        Weapon& operator=(const Weapon& weapon);
    private:
        std::string _type;
};

#endif
