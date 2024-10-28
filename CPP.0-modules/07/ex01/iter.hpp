/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbecker <mbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:17:59 by mbecker           #+#    #+#             */
/*   Updated: 2024/10/28 16:35:46 by mbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
void	iter(T* array, long len, void (*func)(T&))
{
	for (int i = 0; i < len; i++)
		func(array[i]);
}
