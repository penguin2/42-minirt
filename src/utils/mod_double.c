/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_double.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 01:03:02 by taekklee          #+#    #+#             */
/*   Updated: 2023/12/01 12:29:11 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

double	mod_double(double x)
{
	double	tmp;

	x = modf(x, &tmp);
	if (x < 0)
		return (x + 1);
	return (x);
}
