/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvert.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:40:54 by everonel          #+#    #+#             */
/*   Updated: 2024/02/08 16:56:21 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConvert.hpp"

ScalarConvert::ScalarConvert() { }

ScalarConvert::ScalarConvert( ScalarConvert const & src ) { *this = src; }

ScalarConvert::~ScalarConvert() { }

ScalarConvert &	ScalarConvert::operator=( ScalarConvert const & rhs )
{
    (void)rhs;
    return *this;
}

void ScalarConvert::convert(const std::string &literal) {
    if (literal.empty()) {
        _printImpossible();
    }
    else if (_specialCase(literal)) {
        return ;
    }
    else if (literal.size() == 3 && literal[0] == '\'' && literal[2] == '\'') {
        _tryPrintChar(literal[1]);
        _printNumeric(static_cast<int>(literal[1]), static_cast<float>(literal[1]), static_cast<double>(literal[1]));
    } else if (literal.size() == 1 && !isdigit(literal[0])) {
        _tryPrintChar(literal[0]);
        _printNumeric(static_cast<int>(literal[0]), static_cast<float>(literal[0]), static_cast<double>(literal[0]));
    }
    else {
        _tryConvertToNumeric(literal);
    }
}

void ScalarConvert::_tryConvertToNumeric(const std::string &literal) {
    std::istringstream iss(literal);
    double doubleValue;

    if (!(iss >> doubleValue)) {
        _printImpossible();
        return ; 
    }

    int     intValue = static_cast<int>(doubleValue);
    float   floatValue = static_cast<float>(doubleValue);
    if (doubleValue >= 0 && doubleValue <= std::numeric_limits<char>::max()) {
        _tryPrintChar(intValue);
    } else {
        std::cout << "char:   impossible" << std::endl;
    }
    _printNumeric(intValue, floatValue, doubleValue);
}

void ScalarConvert::_tryPrintChar(char c) {
    if (isprint(c)) {
        std::cout << "char:   '" << c << "'" << std::endl;
    } else {
        std::cout << "char:   Non displayable" << std::endl;
    }
}

void ScalarConvert::_printNumeric(int i, float f, double d) {
    std::cout << "int:    " << i << std::endl;
    std::cout << "float:  " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void ScalarConvert::_printImpossible() {
    std::cout << "char:   impossible" << std::endl;
    std::cout << "int:    impossible" << std::endl;
    std::cout << "float:  impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}

bool ScalarConvert::_specialCase(const std::string &literal) {
    if (literal == "nan" || literal == "nanf") {
        std::cout << "char:   impossible" << std::endl;
        std::cout << "int:    impossible" << std::endl;
        std::cout << "float:  nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        return true;
    }
    if (literal == "+inf" || literal == "+inff") {
        std::cout << "char:   impossible" << std::endl;
        std::cout << "int:    impossible" << std::endl;
        std::cout << "float:  inff" << std::endl;
        std::cout << "double: inf" << std::endl;
        return true;
    }
    if (literal == "-inf" || literal == "-inff") {
        std::cout << "char:   impossible" << std::endl;
        std::cout << "int:    impossible" << std::endl;
        std::cout << "float:  -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
        return true;
    }
    return false;
}







