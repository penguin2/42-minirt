/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 02:10:23 by taekklee          #+#    #+#             */
/*   Updated: 2023/12/01 16:21:25 by taekklee         ###   ########.fr       */
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
	t_vec3		orthgonol_to_dir;

	new = ft_xcalloc(1, sizeof(t_cylinder));
	new->center = center;
	dir = vec3_unit(dir);
	orthgonol_to_dir = vec3_some_orthogonal(dir);
	new->system = cartesian_system_create(
			orthgonol_to_dir,
			vec3_cross(dir, orthgonol_to_dir),
			dir);
	new->radius = radius;
	new->half_height = half_height;
	return (new);
}
