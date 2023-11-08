/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:22:55 by everonel          #+#    #+#             */
/*   Updated: 2023/11/08 19:08:48 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

# define RESET      "\033[0m"
# define DEBUG		"\033[33m"
// # define DAMAGE		"\033[31m"
// # define CURE       "\033[32m"

class Animal
{
    public:
        Animal( );
        Animal(std::string type);
        Animal(Animal &copy);
        virtual ~Animal( );

        void virtual    makeSound( ) const;
        std::string     getType( ) const;
        Animal &operator=(Animal &copy);
    protected:
        std::string _type;
};

#endif