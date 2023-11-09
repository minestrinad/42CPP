/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:06:58 by everonel          #+#    #+#             */
/*   Updated: 2023/11/09 13:41:53 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "Void.hpp"

/*virtual ~ICharacter() {}
virtual std::string const & getName() const = 0;
virtual void equip(AMateria* m) = 0;
virtual void unequip(int idx) = 0;
virtual void use(int idx, ICharacter& target) = 0;*/
class Character : public ICharacter {
    private:
        std::string _name;
        AMateria   *_inventory;
        int         _inventory_index;
    public:
        Character(std::string);
        Character(Character &);
        ~Character( );

        std::string const & getName() const;
        void                equip(AMateria *);
        void                unequip(int);
        void                use(int, ICharacter &);

        Character &operator=(Character &);
};

#endif