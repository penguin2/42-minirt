/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_generator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:38:28 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/30 17:44:00 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generator.h"
#include "libft.h"
#include "object.h"
#include "sphere.h"
#include "identifer_and_parameter.h"

t_vla	*sphere_generator(t_object *object)
{
	const t_sphere	*sphere = object->ptr;
	t_vla			*json_sphere_object;

	json_sphere_object = ft_vla_new();
	ft_vla_append(json_sphere_object,
		vec3_to_json_list(&sphere->center, COORDINATES));
	ft_vla_append(json_sphere_object,
		double_to_json_list(sphere->radius * 2.0, DIAMETER));
	ft_vla_append(json_sphere_object,
		color_to_json_list(&object->color, COLORS));
	return (json_sphere_object);
}
