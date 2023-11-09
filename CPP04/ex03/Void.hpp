/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Void.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:18:49 by everonel          #+#    #+#             */
/*   Updated: 2023/11/09 13:43:05 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VOID_HPP
# define VOID_HPP

#include "AMateria.hpp"

class Void : public AMateria {
    private:

    public:
        Void( );
        Void(Void &);
        ~Void();

        std::string const & getType() const;
        AMateria*           clone() const;
        // void                use(ICharacter &);
};

#endif