/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_odd_2d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:16:46 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/17 20:45:19 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	_get_abs_int(double x);

/**
 * @brief using absolute integer values of two coordinates, return
 * 		true if the first bits of those are (1,0) or (0,1)
 * 		false if the first bits of those are (0,0) or (1,1)
 * 
 * @param u first coordinate
 * @param v second coordinate
 */
bool	is_odd_2d(double u, double v)
{
	return ((_get_abs_int(u) & 1) ^ (_get_abs_int(v) & 1));
}

/**
 * @brief getting almost absolute value of the double type value
 * 		ex) 42.21 -> 42
 * 			0.07 -> 0
 * 			-12.34 -> 13
 * 			-0.001 -> 1
 * 
 * @param x double type value
 * @return integer part of the double type value.
 * 		If the value is smaller than zero,
 * 		add 1 to the absolute integer part,
 * 		in order to make the return value alternate when passing zero
 */
static int	_get_abs_int(double x)
{
	if (x < 0)
		return (-(int)x + 1);
	return ((int)x);
}
