/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 22:43:42 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/17 18:29:42 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libvec3.h"
#include "plane.h"

t_plane	*plane_new(t_vec3 origin, t_vec3 normal)
{
	t_plane	*new;

	new = ft_xcalloc(1, sizeof(t_plane));
	new->origin = origin;
	new->normal = vec3_unit(normal);
	new->axis_u = vec3_some_orthogonal(new->normal);
	new->axis_v = vec3_cross(new->normal, new->axis_u);
	return (new);
}
