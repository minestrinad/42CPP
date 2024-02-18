/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 23:18:44 by everonel          #+#    #+#             */
/*   Updated: 2024/02/11 17:37:38 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac != 3)
    {
        std::cerr << "Error: wrong number of arguments" << std::endl;
        return (1);
    }
    try {
        PmergeMe::validateInput(av + 1);
    }
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return (1);
    }
    std::cout << "Before: " << av + 1 << std::endl;
    PmergeMe::PmergeList(av + 1);
    PmergeMe::PmergeVector(av + 1);
    // std::cout << "After: " << PmergeMe::getList() << std::endl;
    // std::cout << "Time to process a range of " << PmergeMe::getSize << " elements with std::list : " << PmergeMe::getListTime() << std::endl;
    // std::cout << "Time to process a range of " << PmergeMe::getSize << " elements with std::vector : " << PmergeMe::getVectorTime() << std::endl;
}