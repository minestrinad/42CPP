/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:46:35 by everonel          #+#    #+#             */
/*   Updated: 2023/11/08 19:03:41 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"

class Dog : public Animal
{
    private:

    public:
        Dog( );
        Dog( std::string );
        Dog( Dog & );
        ~Dog( );

        void        makeSound( ) const;
        std::string getType( ) const;
};

#endif
