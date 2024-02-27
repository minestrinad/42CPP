/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 23:18:44 by everonel          #+#    #+#             */
/*   Updated: 2024/02/27 17:54:04 by everonel         ###   ########.fr       */
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
    if (ac < 3)
    {
        std::cerr << "Error: wrong number of arguments" << std::endl;
        return (1);
    }
    try {
       PmergeMe::validateInput(++av);
    }
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return (1);
    }

    PmergeMe PmergeMe;
    std::cout << "Before: ";
    for (int i = 0; i < ac - 1; i++)
    {
        std::cout << av[i] << " ";
    }
    std::cout << std::endl;
    // PmergeMe.PmergeList(av, ac - 1);
    PmergeMe.PmergeVector(av, ac - 1);
    // std::cout << "List After: ";
    // printContainer<std::list<int> >(PmergeMe.getList());
    std::cout << "After:  ";
    printContainer<std::vector<int> >(PmergeMe.getVector());
    std::cout << std::endl;
    // std::cout << "Time to process a range of " << PmergeMe.getSize() << " elements with std::list : " << PmergeMe.getListTime() << std::endl;
    std::cout << "Time to process a range of " << PmergeMe.getSize();
    std::cout  << " elements with std::vector : " <<(PmergeMe.getVectorTime() / TIME_RESOLUTION) << std::endl;
}