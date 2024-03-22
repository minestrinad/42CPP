/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 23:18:44 by everonel          #+#    #+#             */
/*   Updated: 2024/03/21 16:19:23 by everonel         ###   ########.fr       */
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
        if (ac < 2) {
            std::cerr << "Usage: ./Pmergeme <seq>" << std::endl;
        }
        PmergeMe::validateInput(++av);
    }
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return (1);
    }

    std::cout << "Before: ";
    PmergeMe PmergeMe(ac - 1);
    for (int i = 0; i < ac - 1; i++) {
        std::cout << av[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "After:  ";
    double VTime = PmergeMe.PmergeVector( av );
    double LTime = PmergeMe.PmergeList( av );
    printContainer<std::list<int> >(PmergeMe.getList());
    
    std::cout << "Time to process a range of " << PmergeMe.getSize() << " elements with std::vector : " << std::fixed << VTime << " us" << std::endl;
    std::cout << "Time to process a range of " << PmergeMe.getSize() << " elements with std::list : " << std::fixed << LTime << " us" << std::endl;
}