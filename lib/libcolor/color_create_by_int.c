/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_create_by_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:49:05 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/25 17:51:01 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcolor.h"

t_color	color_create_by_int(int red, int green, int blue)
{
	t_color	new;

	new.red = (double)red / MAX_COLOR_8BIT;
	new.green = (double)green / MAX_COLOR_8BIT;
	new.blue = (double)blue / MAX_COLOR_8BIT;
	return (new);
}
