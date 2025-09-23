/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:42:48 by icunha-t          #+#    #+#             */
/*   Updated: 2025/09/23 15:31:28 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/MutantStack.hpp"

/******************************************************************************/
/*                  Constructors, Copy Constructor, Destructor                 */
/******************************************************************************/
template <typename T, typename C>
MutantStack<T, C>::MutantStack(): std::stack<T, C>() {}

template <typename T, typename C>
MutantStack<T, C>::MutantStack(const MutantStack& src): std::stack<T> (src) {}

template <typename T, typename C>
MutantStack<T, C>::~MutantStack() {}

/******************************************************************************/
/*                                Operators                                   */
/******************************************************************************/
template <typename T, typename C>
MutantStack<T, C>& MutantStack<T, C>::operator= (const MutantStack& src){
    if (this != src)
        std::stack<T, C>::operator= (src);
    return *this;
}

/******************************************************************************/
/*                              Iterator Functions                            */
/******************************************************************************/

template<typename T, typename C>
typename MutantStack<T, C>::iterator MutantStack<T, C>::begin(){
    return this->c.begin();
}

template<typename T, typename C>
typename MutantStack<T, C>::const_iterator MutantStack<T, C>::begin() const{
    return this->c.begin();
}

template<typename T, typename C>
typename MutantStack<T, C>::iterator MutantStack<T, C>::end(){
    return this->c.end();
}

template <typename T, typename C>
typename MutantStack<T, C>::const_iterator MutantStack<T, C>::end() const{
    return this->c.end();
}

template <typename T, typename C>
typename MutantStack<T, C>::reverse_iterator MutantStack<T, C>::rbegin(){
    return this->c.rbegin();
}

template <typename T, typename C>
typename MutantStack<T, C>::const_reverse_iterator MutantStack<T, C>::rbegin() const{
    return this->rbegin();
}

template <typename T, typename C>
typename MutantStack<T, C>::reverse_iterator MutantStack<T, C>::rend(){
    return this->c.rend();
}

template <typename T, typename C>
typename MutantStack<T, C>::const_reverse_iterator MutantStack<T, C>::rend() const{
    return this->c.rend();
}