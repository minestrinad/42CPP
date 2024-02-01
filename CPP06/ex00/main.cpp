/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:04:48 by everonel          #+#    #+#             */
/*   Updated: 2024/01/31 12:33:43 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConvert.hpp"

int main () {
    //Succesfull conversions
    try {
    std::cout << "Succesfull conversions" << std::endl;
    std::string str = "123";
    std::cout << "String: " << str << std::endl;
    std::cout << "char: " << ScalarConvert::convert<char>(str) << std::endl;
    std::cout << "int: " << ScalarConvert::convert<int>(str) << std::endl;
    std::cout << "float: " << ScalarConvert::convert<float>(str) << std::endl;
    std::cout << "double: " << ScalarConvert::convert<double>(str) << std::endl;

    std::string str1 = "-123";
    std::cout << std::endl << "String: " << str1 << std::endl;
    std::cout << "char: " << ScalarConvert::convert<char>(str1) << std::endl;
    std::cout << "int: " << ScalarConvert::convert<int>(str1) << std::endl;
    std::cout << "float: " << ScalarConvert::convert<float>(str1) << std::endl;
    std::cout << "double: " << ScalarConvert::convert<double>(str1) << std::endl;

    std::string str2 = "123.123";
    std::cout << std::endl << "String: " << str2 << std::endl;
    std::cout << "char: " << ScalarConvert::convert<char>(str2) << std::endl;
    std::cout << "int: " << ScalarConvert::convert<int>(str2) << std::endl;
    std::cout << "float: " << ScalarConvert::convert<float>(str2) << std::endl;
    std::cout << "double: " << ScalarConvert::convert<double>(str2) << std::endl;

    std::string str3 = "-123.123";
    std::cout << std::endl << "String: " << str3 << std::endl;
    std::cout << "char: " << ScalarConvert::convert<char>(str3) << std::endl;
    std::cout << "int: " << ScalarConvert::convert<int>(str3) << std::endl;
    std::cout << "float: " << ScalarConvert::convert<float>(str3) << std::endl;
    std::cout << "double: " << ScalarConvert::convert<double>(str3) << std::endl;

    std::string str4 = "123.123f";
    std::cout << std::endl << "String: " << str4 << std::endl;
    std::cout << "char: " << ScalarConvert::convert<char>(str4) << std::endl;
    std::cout << "int: " << ScalarConvert::convert<int>(str4) << std::endl;
    std::cout << "float: " << ScalarConvert::convert<float>(str4) << std::endl;
    std::cout << "double: " << ScalarConvert::convert<double>(str4) << std::endl;

    std::string str5 = "-123.123f";
    std::cout << std::endl << "String: " << str5 << std::endl;
    std::cout << "char: " << ScalarConvert::convert<char>(str5) << std::endl;
    std::cout << "int: " << ScalarConvert::convert<int>(str5) << std::endl;
    std::cout << "float: " << ScalarConvert::convert<float>(str5) << std::endl;
    std::cout << "double: " << ScalarConvert::convert<double>(str5) << std::endl;

    std::string str6 = "+inf";
    std::cout << std::endl << "String: " << str6 << std::endl;
    std::cout << "char: " << ScalarConvert::convert<char>(str6) << std::endl;
    std::cout << "int: " << ScalarConvert::convert<int>(str6) << std::endl;
    std::cout << "float: " << ScalarConvert::convert<float>(str6) << std::endl;
    std::cout << "double: " << ScalarConvert::convert<double>(str6) << std::endl;

    std::string str7 = "-inf";
    std::cout << std::endl << "String: " << str7 << std::endl;
    std::cout << "char: " << ScalarConvert::convert<char>(str7) << std::endl;
    std::cout << "int: " << ScalarConvert::convert<int>(str7) << std::endl;
    std::cout << "float: " << ScalarConvert::convert<float>(str7) << std::endl;
    std::cout << "double: " << ScalarConvert::convert<double>(str7) << std::endl;

    std::string str8 = "nan";
    std::cout << std::endl << "String: " << str8 << std::endl;
    std::cout << "char: " << ScalarConvert::convert<char>(str8) << std::endl;
    std::cout << "int: " << ScalarConvert::convert<int>(str8) << std::endl;
    std::cout << "float: " << ScalarConvert::convert<float>(str8) << std::endl;
    std::cout << "double: " << ScalarConvert::convert<double>(str8) << std::endl;

    std::string str9 = "+inff";
    std::cout << std::endl << "String: " << str9 << std::endl;
    std::cout << "char: " << ScalarConvert::convert<char>(str9) << std::endl;
    std::cout << "int: " << ScalarConvert::convert<int>(str9) << std::endl;
    std::cout << "float: " << ScalarConvert::convert<float>(str9) << std::endl;
    std::cout << "double: " << ScalarConvert::convert<double>(str9) << std::endl;

    std::string str10 = "-inff";
    std::cout << std::endl << "String: " << str10 << std::endl;
    std::cout << "char: " << ScalarConvert::convert<char>(str10) << std::endl;
    std::cout << "int: " << ScalarConvert::convert<int>(str10) << std::endl;
    std::cout << "float: " << ScalarConvert::convert<float>(str10) << std::endl;
    std::cout << "double: " << ScalarConvert::convert<double>(str10) << std::endl;

    std::string str11 = "nanf";
    std::cout << std::endl << "String: " << str11 << std::endl;
    std::cout << "char: " << ScalarConvert::convert<char>(str11) << std::endl;
    std::cout << "int: " << ScalarConvert::convert<int>(str11) << std::endl;
    std::cout << "float: " << ScalarConvert::convert<float>(str11) << std::endl;
    std::cout << "double: " << ScalarConvert::convert<double>(str11) << std::endl;

    //Unsuccesfull conversions
    std::cout << std::endl << "Unsuccesfull conversions" << std::endl;
    std::cout << "char: " << ScalarConvert::convert<char>(".\\o") << std::endl;
    std::cout << "int: " << ScalarConvert::convert<int>("g;/") << std::endl;
    std::cout << "float: " << ScalarConvert::convert<float>("kl'\\[]") << std::endl;
    std::cout << "double: " << ScalarConvert::convert<double>(";l;[;l") << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}