/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 15:18:31 by icunha-t          #+#    #+#             */
/*   Updated: 2025/09/18 17:39:10 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Array.hpp"

/******************************************************************************/
/*                  Constructors, Copy Constructor, Destructor                 */
/******************************************************************************/
template<typename T>
Array<T>::Array(): _elements(NULL), _size(0){}

template<typename T>
Array<T>::Array(unsigned int n): _elements(new T[n]()), _size(n){}

template<typename T>
Array<T>::Array(const Array<T>& src): _elements(new T[src._size]), _size(src._size){
	for (unsigned int i = 0; i < src._size; i++)
		this->_elements[i] = src._elements[i];
}

template<typename T>
Array<T>::~Array(){
	delete[] _elements;
}

/******************************************************************************/
/*                                Operators                                   */
/******************************************************************************/

template<typename T>
Array<T>& Array<T>::operator= (const Array<T>& src){
	if (this != &src){
		delete[] _elements;
		this->_size = src._size;
		this->_elements = new T[_size];
		for (unsigned int i = 0; i < _size; i++){
			this->_elements[i] = src._elements[i];
		}
	}
    return *this;
}

template<typename T>
T& Array<T>::operator[] (unsigned int index){
	if (index >= _size)
		throw std::out_of_range("Index is out of bounds.");
	return this->_elements[index];
}

template<typename T>
const T& Array<T>::operator[] (unsigned int index) const{
	if (index >= _size)
		throw std::out_of_range("Index is out of bounds.");
	return this->_elements[index];
}

/******************************************************************************/
/*                              Member Functions                              */
/******************************************************************************/

template<typename T>
unsigned int Array<T>::size() const{
	return this->_size;
}
