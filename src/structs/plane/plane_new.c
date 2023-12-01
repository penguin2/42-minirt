/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 22:43:42 by taekklee          #+#    #+#             */
/*   Updated: 2023/12/01 12:33:25 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libvec3.h"
#include "plane.h"

t_plane	*plane_new(t_vec3 origin, t_vec3 normal)
{
	t_plane	*new;
	t_vec3	orthgonol_to_normal;

	new = ft_xcalloc(1, sizeof(t_plane));
	new->origin = origin;
	new->normal = vec3_unit(normal);
	orthgonol_to_normal = vec3_some_orthogonal(new->normal);
	new->system = cartesian_system_create(
			orthgonol_to_normal,
			vec3_cross(new->normal, orthgonol_to_normal),
			new->normal);
	return (new);
}
