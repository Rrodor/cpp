/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 01:05:40 by rrodor            #+#    #+#             */
/*   Updated: 2023/09/08 01:17:36 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T> void iter(T *array, int lenght, void (*function)(T*))
{
	for (int i = 0; i < lenght; i++)
		function(&array[i]);
}
