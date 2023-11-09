/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:24:13 by everonel          #+#    #+#             */
/*   Updated: 2023/11/08 19:10:31 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    private:
        
    public:
        WrongCat( );
        WrongCat( std::string );
        WrongCat( WrongCat & );
        ~WrongCat( );

        void        makeSound() const;
        std::string getType() const;
};


#endif