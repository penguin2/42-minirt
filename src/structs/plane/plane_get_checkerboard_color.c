/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_get_checkerboard_color.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 01:11:13 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/17 01:14:05 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "plane.h"

t_color	plane_get_checkerboard_color(const t_plane *plane, t_vec3 pos)
{
	(void)plane;
	(void)pos;
	return (color_white());
}
