/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_objects_to_json_dict.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:06:38 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/30 19:59:53 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generator.h"
#include "object.h"
#include <stddef.h>

t_json_node	*convert_objects_to_json_dict(t_vla *objects,
											const char *identifer,
											t_object_id object_id,
											t_vla *(*generator)(t_object *))
{
	t_json_node	*json_dict;
	t_object	*object;
	size_t		idx;

	json_dict = NULL;
	idx = 0;
	while (idx < objects->size)
	{
		object = objects->array[idx++];
		if (object->get_id() == object_id)
		{
			if (json_dict == NULL)
				json_dict = json_node_new(
						ft_strdup(identifer),
						ft_vla_new(),
						NODE_LIST);
			ft_vla_append(json_dict->value,
				json_node_new(NULL, generator(object), NODE_DICT));
		}
	}
	return (json_dict);
}
