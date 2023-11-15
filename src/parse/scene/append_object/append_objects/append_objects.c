/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_objects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:59:11 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/14 14:51:11 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "define.h"

int	append_objects(const t_json_node *node, t_vla *objects)
{
	if (append_object_to_vla(node, objects, ID_SPHERE, append_sphere) == ERROR
		|| append_object_to_vla(node, objects, ID_PLANE, append_plane) == ERROR
		|| append_object_to_vla(
			node,
			objects,
			ID_CYLINDER,
			append_cylinder) == ERROR
		|| append_object_to_vla(
			node,
			objects,
			ID_TRIANGLE,
			append_triangle) == ERROR
		|| append_object_to_vla(
			node,
			objects,
			ID_QUADRIC,
			append_quadric) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
