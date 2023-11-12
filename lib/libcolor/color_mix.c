/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_mix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 22:05:54 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/12 22:10:00 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcolor.h"

t_color	color_mix(t_color color1, t_color color2, double t)
{
	return (color_create(
			t * color1.red + (1 - t) * color2.red,
			t * color1.blue + (1 - t) * color2.blue,
			t * color1.green + (1 - t) * color2.green));
}
