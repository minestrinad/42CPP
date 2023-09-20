/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 13:30:24 by everonel          #+#    #+#             */
/*   Updated: 2023/09/19 13:35:30 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include "Zombie.h"

Class Zombie
{
    public:
        Zombie(std::string name, std::string type);
        ~Zombie(void);
        void	announce(void);
    private:
        std::string _name;
        std::string _type;
};

#endif