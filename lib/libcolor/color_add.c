/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 01:04:04 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/02 01:07:14 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcolor.h"

t_color	color_add(t_color color1, t_color color2)
{
	return (color_create(
			color1.red + color2.red,
			color1.green + color2.green,
			color1.blue + color2.blue));
}
