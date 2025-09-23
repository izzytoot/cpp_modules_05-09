/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabeltootill <isabeltootill@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:05:04 by isabeltooti       #+#    #+#             */
/*   Updated: 2025/09/22 17:56:49 by isabeltooti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"

template<typename it>
void Span::addMultiple(it start, it end){
    unsigned int qt = std::distance(start, end);
    if ((this->_N.size() + qt) > this->_max){ 
        throw LackSpace();
    }
    _N.insert(_N.end(), start, end);
}
