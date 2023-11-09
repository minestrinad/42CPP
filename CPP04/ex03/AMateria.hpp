/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 23:11:14 by everonel          #+#    #+#             */
/*   Updated: 2023/11/08 23:40:28 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class AMateria
{
    protected:
        std::string _type;
    public:
        AMateria(std::string const & type);
        AMateria(AMateria &);
        ~AMateria();

        std::string const & getType() const; //Returns the materia type
        virtual AMateria*   clone() const = 0;
        virtual void        use(ICharacter& target);

        AMateria &operator=(AMateria &);
};

#endif