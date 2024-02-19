/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 23:18:44 by everonel          #+#    #+#             */
/*   Updated: 2024/02/19 20:41:06 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac < 3)
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

    PmergeMe PmergeMe;
    // PmergeMe.PmergeList(av, ac - 1);
    PmergeMe.PmergeVector(av, ac - 1);
    // std::cout << "After: " << PmergeMe.getList() << std::endl;
    // std::cout << "Time to process a range of " << PmergeMe.getSize() << " elements with std::list : " << PmergeMe.getListTime() << std::endl;
    std::cout << "Time to process a range of " << PmergeMe.getSize() << " elements with std::vector : " << PmergeMe.getVectorTime() << std::endl;
}