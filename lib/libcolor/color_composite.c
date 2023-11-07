/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_composite.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:50:36 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/05 15:51:39 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcolor.h"

t_color	color_composite(t_color color1, t_color color2)
{
	return (color_create(
			color1.red * color2.red,
			color1.blue * color2.blue,
			color1.green * color2.green));
}
