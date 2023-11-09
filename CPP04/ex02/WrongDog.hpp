/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:46:35 by everonel          #+#    #+#             */
/*   Updated: 2023/11/08 19:11:44 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGDOG_HPP
# define WRONGDOG_HPP

# include <iostream>
# include "WrongAnimal.hpp"

class WrongDog : public WrongAnimal
{
    private:

    public:
        WrongDog( );
        WrongDog( std::string );
        WrongDog( WrongDog & );
        ~WrongDog( );

        void        makeSound( ) const;
        std::string getType( ) const;
};

#endif
