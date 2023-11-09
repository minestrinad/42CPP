/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:45:09 by everonel          #+#    #+#             */
/*   Updated: 2023/11/09 21:10:45 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource{
    private:
        AMateria *_knowledge[4];
    public:
        MateriaSource( );
        ~MateriaSource() {}
        virtual void        learnMateria(AMateria*);
        virtual AMateria*   createMateria(std::string const & type);

};

#endif