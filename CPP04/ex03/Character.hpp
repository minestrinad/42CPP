/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:06:58 by everonel          #+#    #+#             */
/*   Updated: 2023/11/09 23:50:06 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character : public ICharacter 
{

    public:
        Character(std::string);
        Character(Character &);
        ~Character( );

        std::string const & getName() const;
        void                equip(AMateria *);
        void                unequip(int);
        void                use(int, ICharacter &);

        Character &operator=(Character &);
    private:
        std::string _name;
        AMateria    *_inventory[DIM_INVENTORY];
        AMateria    *_floor[DIM_FLOOR];
};

#endif