/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_generator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:47:16 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/30 17:44:15 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generator.h"
#include "libft.h"
#include "object.h"
#include "cylinder.h"
#include "identifer_and_parameter.h"

t_vla	*cylinder_generator(t_object *object)
{
	const t_cylinder	*cylinder = object->ptr;
	t_vla				*json_cylinder_object;

	json_cylinder_object = ft_vla_new();
	ft_vla_append(json_cylinder_object,
		vec3_to_json_list(&cylinder->center, COORDINATES));
	ft_vla_append(json_cylinder_object,
		vec3_to_json_list(&cylinder->dir, AXIS));
	ft_vla_append(json_cylinder_object,
		double_to_json_list(cylinder->radius * 2.0, DIAMETER));
	ft_vla_append(json_cylinder_object,
		double_to_json_list(cylinder->half_height * 2.0, HEIGHT));
	ft_vla_append(json_cylinder_object,
		color_to_json_list(&object->color, COLORS));
	return (json_cylinder_object);
}
