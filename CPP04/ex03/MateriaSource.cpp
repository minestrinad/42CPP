/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:46:36 by everonel          #+#    #+#             */
/*   Updated: 2023/11/09 21:24:30 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
MateriaSource::MateriaSource( ) {
    for (int i = 0; i < KNOWLEDGE_DIM; i++)
        _knowledge[i] = NULL;
    std::cout << "A MateriaSource has been allocated" << std::endl;
}


// learnMateria(AMateria*)
// Copies the Materia passed as a parameter and store it in memory so it can be cloned
// later. Like the Character, the MateriaSource can know at most 4 Materias. They
// are not necessarily unique.
void MateriaSource::learnMateria(AMateria *src) {
    for (int i = 0; i < KNOWLEDGE_DIM; i++)
        if (_knowledge[i] == NULL)
            _knowledge[i] = src;
}

// • createMateria(std::string const &)
// Returns a new Materia. The latter is a copy of the Materia previously learned by
// the MateriaSource whose type equals the one passed as parameter. Returns 0 if
// the type is unknown.
AMateria *MateriaSource::createMateria(std::string const & type) {
    AMateria *clone = NULL;
    
    for (int i = 0; i < KNOWLEDGE_DIM; i++)
        if (_knowledge[i]->getType() == type)
            clone = _knowledge[i]->clone();
    if (clone == NULL)
        std::cout << "Sorry you haven't read that manual page yet" << std::endl;
}




// In a nutshell, your MateriaSource must be able to learn "templates" of Materias to
// create them when needed. Then, you will be able to generate a new Materia using just
// a string that identifies its type.