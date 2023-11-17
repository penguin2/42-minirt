/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 02:10:23 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/17 19:34:49 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"
#include "libft.h"

t_cylinder	*cylinder_new(
				t_vec3 center,
				t_vec3 dir,
				double radius,
				double half_height)
{
	t_cylinder	*new;

	new = ft_xcalloc(1, sizeof(t_cylinder));
	new->center = center;
	new->dir = vec3_unit(dir);
	new->axis_u = vec3_some_orthogonal(new->dir);
	new->axis_v = vec3_cross(new->dir, new->axis_u);
	new->radius = radius;
	new->half_height = half_height;
	return (new);
}
