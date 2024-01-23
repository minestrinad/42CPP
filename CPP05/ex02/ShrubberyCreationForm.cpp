/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 01:48:25 by everonel          #+#    #+#             */
/*   Updated: 2024/01/21 23:57:18 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : AForm("ShrubberyCreationForm", 145, 137), _target(target + "_shrubbery") { }

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &src ) { *this = src; }

ShrubberyCreationForm::~ShrubberyCreationForm( ) { }

void    ShrubberyCreationForm::execute( ) { 
    std::fstream fd;
    fd.open(_target, std::fstream::in | std::fstream::out | std::fstream::trunc);
    fd << "             .        +          .      .          ." << std::endl;
    fd << "     .            _        .                    ." << std::endl;
    fd << "  ,              /;-._,-.____        ,-----.__" << std::endl;
    fd << " ((        .    (_:#::_.:::. `-._   /:, /-._, `._," << std::endl;
    fd << "  `                 \\   _|`\"=:_::.`.);  \\ __/ /" << std::endl;
    fd << "                      ,    `./  \\:. `.   )==-'  ." << std::endl;
    fd << "    .      ., ,-=-.  ,\\, +#./`   \\:.  / /           ." << std::endl;
    fd << ".           \\/:/`-' , ,\\ '` ` `   ): , /_  -o" << std::endl;
    fd << "       .    /:+- - + +- : :- + + -:'  /(o-) \\)     ." << std::endl;
    fd << "  .      ,=':  \\    ` `/` ' , , ,:' `'--\".--\"---._/`7" << std::endl;
    fd << "   `.   (    \\: \\,-._` ` + '\\, ,\"   _,--._,---\":.__/" << std::endl;
    fd << "              \\:  `  X` _| _,\\/'   .-'" << std::endl;
    fd << ".               \":._:`\\____  /:'  /      .           ." << std::endl;
    fd << "                    \\::.  :\\/:'  /              +" << std::endl;
    fd << "   .                 `.:.  /:'  }      ." << std::endl;
    fd << "           .           ):_(:;   \\           ." << std::endl;
    fd << "                      /:. _/ ,  |" << std::endl;
    fd << "                   . (|::.     ,`                  ." << std::endl;
    fd << "     .                |::.    {" << std::endl;
    fd << "                      |::.\\  \\ `." << std::endl;
    fd << "                      |:::(\\    |" << std::endl;
    fd << "              O       |:::/{ }  |                   (o" << std::endl;
    fd << "               )  ___/#\\::`/ (O \"==._____   O, (O  /`" << std::endl;
    fd << "          ~~~w/w~\"~~,\\` `:/,-(~`\"~~~~~~~~\"~o~\\~/~w|/~" << std::endl;
    fd << "      ~~~~~~~~~~~~~~~~~~~~~~~\\W~~~~~~~~~~~~\\|/~~" << std::endl;
    fd.close();
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm & src) {
    if (this == &src)
        return *this;
    _target = src._target;
    return *this;
}

