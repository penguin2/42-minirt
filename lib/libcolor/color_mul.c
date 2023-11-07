/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_mul.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:28:11 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/05 16:22:49 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcolor.h"

t_color	color_mul(t_color color, double scalar)
{
	return (color_create(
			color.red * scalar,
			color.green * scalar,
			color.blue * scalar));
}
