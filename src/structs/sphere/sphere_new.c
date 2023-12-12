/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:26:14 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/29 19:43:04 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cartesian_system.h"
#include "libft.h"
#include "libvec3.h"
#include "sphere.h"

t_sphere	*sphere_new(t_vec3 center, double radius)
{
	t_sphere	*new;

	new = ft_xcalloc(1, sizeof(t_sphere));
	new->center = center;
	new->radius = radius;
	new->system = cartesian_system_create(
			vec3_unit_x(),
			vec3_unit_y(),
			vec3_unit_z());
	return (new);
}
