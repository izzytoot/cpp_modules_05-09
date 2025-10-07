/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 12:38:49 by icunha-t          #+#    #+#             */
/*   Updated: 2025/10/03 12:48:02 by icunha-t         ###   ########.fr       */
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
        exchange.loadDataBase("../files/data.csv");
    }catch(std::exception& e){
        e.what();
    }
}