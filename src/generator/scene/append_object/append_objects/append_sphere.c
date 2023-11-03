/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:18:23 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/01 19:40:53 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fn_type.h"
#include "sphere.h"
#include "define.h"
#include "generator.h"

static void	_append_sphere_object(t_sphere sphere,
									double diameter,
									t_vla *objects)
{
	t_sphere	*new_sphere;
	t_object	*sphere_object;

	new_sphere = sphere_new(sphere.center, diameter / 2);
	sphere_object = object_new(
			new_sphere,
			sphere_get_dist,
			sphere_get_normal,
			sphere_free);
	ft_vla_append(objects, sphere_object);
}

int	append_sphere(const t_json_node *node, t_vla *objects)
{
	t_sphere			sphere;
	const t_json_node	*diameter_node = select_json_node(node, DIAMETER);
	double				diameter;

	if (list_to_vec3(get_list(node, COORDINATES, 3),
			&sphere.center,
			UNLIMITED,
			UNLIMITED) == ERROR
		|| json_node_to_double(diameter_node,
			&diameter,
			UNLIMITED,
			UNLIMITED) == ERROR)
		return (ERROR);
	_append_sphere_object(sphere, diameter, objects);
	return (SUCCESS);
}
