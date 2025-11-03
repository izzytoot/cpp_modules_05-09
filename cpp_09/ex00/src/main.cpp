/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabeltootill <isabeltootill@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 12:38:49 by icunha-t          #+#    #+#             */
/*   Updated: 2025/11/02 11:17:50 by isabeltooti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"

int main(int ac, char **av){
    if (ac != 2){
        std::cerr << RED << "Error. Usage: ./btc <inputfile.txt>" << RES << std::endl;
        return 1;
    }
    
    BitcoinExchange exchange;
    try{
        exchange.loadDataBase("files/data.csv");
        exchange.convert(av[1]);
    }catch(std::exception& e){
        std::cout << e.what() << std::endl;;
    }

    return 0;
}