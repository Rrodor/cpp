/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 01:36:43 by rrodor            #+#    #+#             */
/*   Updated: 2023/09/12 16:07:33 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdexcept>

template <class T>
class Array
{
	private:
		T	*_array;
		int	_size;
	public:
		Array();
		Array(const Array & ref);
		Array & operator=(const Array & ref);
		~Array();

		Array(unsigned int n);
		T operator[](int n) const;
		T & operator[](int n);
		int	size();

		class OutOfBoundException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

template <class T>
Array<T>::Array()
{
	this->_array = new T[0];
	this->_size = 0;
}

template <class T>
Array<T>::Array(const Array<T> & ref)
{
	this = *ref;
}

template <class T>
Array<T> & Array<T>::operator=(const Array<T> & ref)
{
	delete [] this->_array;
	this->_array = new T[ref._size];
	this->_size = ref._size;
	for (int i = 0; i < ref._size; i++)
		this->_array[i] = ref._array[i];
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
	this->_size = n;
}

template <class T>
T Array<T>::operator[](int n) const
{
	T	x;

	if (n > this->_size - 1)
		throw Array::OutOfBoundException();
	x = this->_array[n];
	return (x);
}

template <class T>
T  & Array<T>::operator[](int n)
{
	if (n > this->_size - 1)
		throw Array::OutOfBoundException();
	return (this->_array[n]);
}

template <class T>
int	Array<T>::size()
{
	return this->_size;
}

template <class T>
const char* Array<T>::OutOfBoundException::what() const throw()
{
	return ("indice is out of bound");
}
