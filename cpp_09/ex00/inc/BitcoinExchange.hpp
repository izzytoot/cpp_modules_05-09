/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 12:39:21 by icunha-t          #+#    #+#             */
/*   Updated: 2025/10/03 12:58:16 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>
#include <map>
#include <ctime>
#include <sstream>
#include <fstream>

#define RED "\033[0;31m"
#define GRN "\033[0;32m"  
#define YEL "\033[0;33m"
#define CYA "\033[36m" 
#define BRED "\033[31;1m"
#define BGRN "\033[32;1m"
#define BYEL "\033[33;1m"
#define BCYA "\033[36;1m"
#define RES "\033[0m"

class BitcoinExchange{
    private:
        std::map<std::string, float> _db;

        float getRate(const std::string& date) const;
        std::string trimString(std::string str) const;
        bool isValidDate(const std::string& date);
        bool isValidRate(const std::string& rateStr, float& rateFloat);

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& src);
        BitcoinExchange& operator= (const BitcoinExchange& src);
        ~BitcoinExchange();

        void loadDataBase(const std::string& filename);
        bool parseInput(std::string fname);
};
