/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_generator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:43:47 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/30 16:47:09 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generator.h"
#include "libft.h"
#include "object.h"
#include "plane.h"
#include "identifer_and_parameter.h"

t_vla	*plane_generator(t_object *object)
{
	const t_plane	*plane = object->ptr;
	t_vla			*json_plane_object;

	json_plane_object = ft_vla_new();
	ft_vla_append(json_plane_object,
		vec3_to_json_list(&plane->origin, COORDINATES));
	ft_vla_append(json_plane_object,
		vec3_to_json_list(&plane->normal, NORMAL));
	ft_vla_append(json_plane_object,
		color_to_json_list(&object->color, COLORS));
	return (json_plane_object);
}
