/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:15:37 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/08 20:29:38 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libvec3.h"
#include "triangle.h"

t_triangle	*triangle_new(t_vec3 vertex[3])
{
	t_triangle	*new;
	t_vec3		area;

	new = ft_xcalloc(1, sizeof(t_triangle));
	new->origin = vertex[0];
	new->edge[0] = vec3_sub(vertex[1], vertex[0]);
	new->edge[1] = vec3_sub(vertex[2], vertex[0]);
	area = vec3_cross(new->edge[0], new->edge[1]);
	new->normal = vec3_unit(area);
	new->area = vec3_len(area);
	return (new);
}
