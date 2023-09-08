/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 01:36:43 by rrodor            #+#    #+#             */
/*   Updated: 2023/09/08 02:21:30 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <class T>
class Array
{
	private:
		T	*_array;
	public:
		Array();
		Array(const Array & ref);
		Array & operator=(const Array & ref);
		~Array();

		Array(unsigned int n);
};

template <class T>
Array<T>::Array()
{
	this->_array = new T[0];
}

template <class T>
Array<T>::Array(const Array<T> & ref)
{
	this->_array = ref->_array;
}

template <class T>
Array<T> & Array<T>::operator=(const Array<T> & ref)
{
	this->_array = ref->_array;
	return *this;
}

template <class T>
Array<T>::~Array()
{
	delete [] _array;
}

template <class T>
Array<T>::Array(unsigned int n)
{
	this->_array = new T[n];
}
