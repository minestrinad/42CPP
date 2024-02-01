/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 20:47:12 by everonel          #+#    #+#             */
/*   Updated: 2024/01/31 21:06:15 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

void sum2(int &val) {
    val += 2;
}

int main () {
    int arr[] = { 1, 2, 3, 4, 5, 6, 7};
    iter(arr, 7, sum2);

    for (int i = 0; i < 7; i++) {
        std::cout << arr[i] << std::endl;
    }
}
