/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:22:55 by everonel          #+#    #+#             */
/*   Updated: 2023/11/08 23:05:14 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

# define RESET      "\033[0m"
# define DEBUG		"\033[33m"
// # define DAMAGE		"\033[31m"
// # define CURE       "\033[32m"

class AAnimal
{
    public:
        AAnimal( );
        AAnimal(std::string type);
        AAnimal(AAnimal &copy);
        virtual ~AAnimal( );

        void virtual    makeSound( ) const = 0;
        std::string     getType( ) const;
        AAnimal &operator=(AAnimal &copy);
    protected:
        std::string _type;
};

#endif