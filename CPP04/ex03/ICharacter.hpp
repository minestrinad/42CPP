/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 23:14:35 by everonel          #+#    #+#             */
/*   Updated: 2023/11/08 23:55:48 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

class ICharacter
{ 
    public:
        virtual std::string getName() {
            return (NULL); 
    }
};

class Fighter : public ICharacter {
    private:
        std::string _name;
    public:
        Fighter(std::string name) {
            _name = name;
        }
        Fighter( Fighter &src ) {
            *this = src;
        }
        ~Fighter() {}

        std::string getName( ) {
            return _name;
        }
        
        Fighter &operator=(Fighter &src) {
            _name = src._name;
            return *this;
        }
};
#endif