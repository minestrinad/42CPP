/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:18:49 by everonel          #+#    #+#             */
/*   Updated: 2023/11/09 19:06:42 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {
    public:
        Ice( );
        ~Ice( );

        AMateria*           clone() const;
        void                use(ICharacter &);
        Ice &operator=( const Ice & );      
};

#endif