/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 23:18:44 by everonel          #+#    #+#             */
/*   Updated: 2024/03/20 15:18:18 by everonel         ###   ########.fr       */
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
    std::cout << "Welcome to PmergeMe" << std::endl;
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
    printContainer<std::list<int> >(PmergeMe.getList());
    
    std::cout << "After:  ";
    double VTime = PmergeMe.PmergeVector( );
    double LTime = PmergeMe.PmergeList( );
    printContainer<std::list<int> >(PmergeMe.getList());
    
    std::cout << "Time to process a range of " << PmergeMe.getSize() << " elements with std::vector : " << std::fixed << VTime << " us" << std::endl;
    std::cout << "Time to process a range of " << PmergeMe.getSize() << " elements with std::list : " << std::fixed << LTime << " us" << std::endl;
}