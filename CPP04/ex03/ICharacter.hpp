/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 23:14:35 by everonel          #+#    #+#             */
/*   Updated: 2023/11/09 23:49:14 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# define DIM_FLOOR      2000
# define DIM_INVENTORY  4

# include "AMateria.hpp"

class ICharacter
{ 
    public:
        virtual ~ICharacter() { }
        virtual std::string const & getName() const = 0;
        virtual void                equip(AMateria* m) = 0;
        virtual void                unequip(int idx) = 0;
        virtual void                use(int idx, ICharacter& target) = 0;
};

#endif