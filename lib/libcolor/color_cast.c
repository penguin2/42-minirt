/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_cast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:34:43 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/18 20:42:49 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcolor.h"

static int	_double_to_8bit(double val);

int	color_cast(t_color color)
{
	return ((_double_to_8bit(color.red) << 16)
		| (_double_to_8bit(color.green) << 8)
		| (_double_to_8bit(color.blue)));
}

static int	_double_to_8bit(double val)
{
	if (val > 1.0)
		return (0xff);
	if (val < 0.0)
		return (0x00);
	return (0xff * val);
}
