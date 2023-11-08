/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:22:55 by everonel          #+#    #+#             */
/*   Updated: 2023/11/08 19:16:40 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

# define RESET      "\033[0m"
# define DEBUG		"\033[33m"
// # define DAMAGE		"\033[31m"
// # define CURE       "\033[32m"

class WrongAnimal
{
    public:
        WrongAnimal( );
        WrongAnimal(std::string type);
        WrongAnimal(WrongAnimal &copy);
        virtual ~WrongAnimal( );

        void        makeSound( ) const;
        std::string getType( ) const;
        
        WrongAnimal &operator=(WrongAnimal &copy);
    protected:
        std::string _type;
};

#endif