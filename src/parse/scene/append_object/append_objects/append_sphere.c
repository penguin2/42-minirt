/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:18:23 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/17 01:54:06 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sphere.h"
#include "define.h"
#include "parse.h"
#include "utils.h"
#include <float.h>

int	append_sphere(const t_json_node *node, t_vla *objects)
{
	t_sphere			sphere;
	const t_json_node	*diameter_node = select_json_node(node, DIAMETER);
	double				diameter;

	if (list_to_vec3(get_list(node, COORDINATES, 3),
			&sphere.center, NO_LIMIT, NO_LIMIT) == ERROR
		|| json_node_to_double(
			diameter_node, &diameter, DBL_MIN, DBL_MAX
		) == ERROR)
		return (ERROR);
	ft_vla_append(objects, sphere_object_new(sphere.center, diameter / 2));
	return (SUCCESS);
}
