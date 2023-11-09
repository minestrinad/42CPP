/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:18:49 by everonel          #+#    #+#             */
/*   Updated: 2023/11/09 13:48:18 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {
    private:

    public:
        Ice( );
        Ice(Ice &);
        ~Ice();

        std::string const & getType() const;
        AMateria*           clone() const;
        void                use(ICharacter &);

        
};

#endif