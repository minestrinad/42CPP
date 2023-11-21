/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 23:11:14 by everonel          #+#    #+#             */
/*   Updated: 2023/11/09 23:52:47 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

//          colors
# define RESET      "\033[0m"
# define DEBUG		"\033[33m"

# include <iostream>
# include "ICharacter.hpp"

class AMateria
{

    public:
        AMateria(std::string const & type);
        virtual ~AMateria() { };
        
        std::string const & getType() const; //Returns the materia type
        virtual AMateria*   clone() const = 0;
        virtual void        use(ICharacter& target);
    
    protected:
        std::string _type;
};

#endif