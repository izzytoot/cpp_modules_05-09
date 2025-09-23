/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:42:48 by icunha-t          #+#    #+#             */
/*   Updated: 2025/09/23 14:46:50 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/MutantStack.hpp"

/******************************************************************************/
/*                  Constructors, Copy Constructor, Destructor                 */
/******************************************************************************/
template <typename T, typename C>
MutantStack<T, C>::MutantStack(): std::stack<T, C> {}

template <typename T, typename C>
MutantStack<T, C>::MutantStack(const MutantStack<T, C>& src): std::stack<T> (src) {}

template <typename T, typename C>
MutantStack<T, C>::~MutantStack() {}

/******************************************************************************/
/*                                Operators                                   */
/******************************************************************************/
template <typename T, typename C>
MutantStack<T, C>& MutantStack<T, C>::operator= (const MutantStack<T, C>& src){
    if (this != src)
        std::stack<T, C>::operator= (src);
    return *this;
}

/******************************************************************************/
/*                              Member Functions                              */
/******************************************************************************/
