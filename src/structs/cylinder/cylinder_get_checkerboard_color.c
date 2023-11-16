/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_get_checkerboard_color.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 01:35:24 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/17 01:36:56 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"

t_color	cylinder_get_checkerboard_color(
				const t_cylinder *cylinder,
				t_vec3 pos)
{
	(void)pos;
	(void)cylinder;
	return (color_white());
}
