/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 00:29:26 by emma              #+#    #+#             */
/*   Updated: 2023/11/19 16:03:31 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat b1("emma", 1);
    Bureaucrat b2("everonel", 150);
    Bureaucrat b3("betty", 0);
    b1.incrementGrade();
    b2.decrementGrade();
    return 0;
}
