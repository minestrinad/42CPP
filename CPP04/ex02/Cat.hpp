/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:24:13 by everonel          #+#    #+#             */
/*   Updated: 2023/11/08 23:06:27 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal
{
    private:
        Brain *_brain;

    public:
        Cat( );
        Cat( std::string );
        Cat( Cat & );
        ~Cat( );

        void        makeSound() const;
        std::string getType() const;
};


#endif