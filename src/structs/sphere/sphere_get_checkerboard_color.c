/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_get_checkerboard_color.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 01:23:23 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/17 01:23:47 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcolor.h"
#include "sphere.h"

t_color	sphere_get_checkerboard_color(const t_sphere *sphere, t_vec3 pos)
{
	(void)pos;
	(void)sphere;
	return (color_white());
}
