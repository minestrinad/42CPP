/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:18:49 by everonel          #+#    #+#             */
/*   Updated: 2023/11/09 18:57:56 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria {
    private:

    public:
        Cure( );
        ~Cure( );

        AMateria*           clone( ) const;
        void                use(ICharacter &);
        Cure &operator=( const Cure & );
};

#endif