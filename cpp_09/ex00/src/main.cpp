/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabeltootill <isabeltootill@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 12:38:49 by icunha-t          #+#    #+#             */
/*   Updated: 2025/10/15 23:45:29 by isabeltooti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"

int main(int ac, char **av){
    if (ac != 2){
        std::cerr << "Error. Usage: ./btc <inputfile.txt>";
        return 1;
    }
    
    BitcoinExchange exchange;
    try{
        exchange.loadDataBase("files/data.csv");
        exchange.convert(av[1]);
    }catch(std::exception& e){
        std::cout << e.what();
    }

    return 0;
}