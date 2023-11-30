/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_lights_to_json_dict.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:23:38 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/30 19:58:34 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generator.h"
#include "light.h"
#include <stddef.h>

t_json_node	*convert_lights_to_json_dict(t_vla *lights,
										const char *identifer,
										t_light_id light_id,
										t_vla *(*generator)(t_light *))
{
	t_json_node	*json_dict;
	t_light		*light;
	size_t		idx;

	json_dict = NULL;
	idx = 0;
	while (idx < lights->size)
	{
		light = lights->array[idx++];
		if (light->get_id() == light_id)
		{
			if (json_dict == NULL)
				json_dict = json_node_new(
						ft_strdup(identifer),
						ft_vla_new(),
						NODE_LIST);
			ft_vla_append(json_dict->value,
				json_node_new(NULL, generator(light), NODE_DICT));
		}
	}
	return (json_dict);
}
