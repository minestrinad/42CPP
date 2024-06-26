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
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
    // Successfull tests
    std::cout << "Successfull tests" << std::endl;
    try
    {
		//Successfull tests
		Bureaucrat bureaucrat("Bureaucrat1", 1);
		ShrubberyCreationForm shrubberyCreationForm("Shrubbery");
		std::cout << shrubberyCreationForm << std::endl;
		PresidentialPardonForm presidentialPardonForm("Presidential");
		std::cout << presidentialPardonForm << std::endl;
		RobotomyRequestForm robotomyRequestForm("Robotomy");
		std::cout << robotomyRequestForm << std::endl;
		bureaucrat.signForm(shrubberyCreationForm);
		bureaucrat.signForm(presidentialPardonForm);
		bureaucrat.signForm(robotomyRequestForm);
		bureaucrat.executeForm(shrubberyCreationForm);
		bureaucrat.executeForm(presidentialPardonForm);
		bureaucrat.executeForm(robotomyRequestForm);
		//Unsuccessfull tests
		Bureaucrat bureaucrat2("Bureaucrat2", 150);
		bureaucrat2.executeForm(shrubberyCreationForm);
		bureaucrat2.executeForm(presidentialPardonForm);
		bureaucrat2.executeForm(robotomyRequestForm);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
    return 0;
}
