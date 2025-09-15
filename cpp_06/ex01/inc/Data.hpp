/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabeltootill <isabeltootill@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 15:05:08 by isabeltooti       #+#    #+#             */
/*   Updated: 2025/09/15 20:10:51 by isabeltooti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iomanip>
#include <string>
#include <iostream>

class Data{
    private:
        std::string _info;
    public:
        void setInfo(std::string info);
        std::string getInfo();

};