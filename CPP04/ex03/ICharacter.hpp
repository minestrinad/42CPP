/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 23:14:35 by everonel          #+#    #+#             */
/*   Updated: 2023/11/09 21:51:27 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include <iostream>
# include "AMateria.hpp"
#include "ICharacter.hpp"

# define RESET      "\033[0m"
# define DEBUG		"\033[33m"

class ICharacter
{ 
    public:
        virtual ~ICharacter() { }
        virtual std::string const & getName() const = 0;
        virtual void                equip(AMateria *) = 0;
        virtual void                unequip(int idx) = 0;
        virtual void                use(int idx, ICharacter& target) = 0;
};

#endif