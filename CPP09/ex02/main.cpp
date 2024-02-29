/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 23:18:44 by everonel          #+#    #+#             */
/*   Updated: 2024/02/29 00:42:31 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template<class T>void printContainer(const T &c)
{
    for (typename T::const_iterator it = c.begin(); it != c.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main(int ac, char **av)
{
    try {
        if (ac < 3) {
            std::cerr << "Error: wrong number of arguments" << std::endl;
        }
        PmergeMe::validateInput(++av);
    }
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return (1);
    }

    std::cout << "Before: ";
    PmergeMe PmergeMe(ac - 1, av);
    printContainer<std::vector<int> >(PmergeMe.getVector());

    std::cout << "After:  ";
    int VTime = PmergeMe.PmergeVector( );
    printContainer<std::vector<int> >(PmergeMe.getVector());
    
    std::cout << "Time to process a range of " << PmergeMe.getSize() << " elements with std::vector : " << VTime / TIME_RESOLUTION << std::endl;
    // std::cout << "Time to process a range of " << LTime << " elements with std::list : " << PmergeMe.getListTime() << std::endl;
}