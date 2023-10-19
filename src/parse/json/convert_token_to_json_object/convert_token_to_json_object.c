/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_token_to_json_object.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:46:40 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/19 20:46:41 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

static void	_set_indexes(t_vla *json_object, size_t indexes[BRACKETS])
{
	char	*str;
	int		open_bracket_char;
	size_t	idx;

	idx = 0;
	while (idx < json_object->size)
	{
		if (((t_node *)json_object->array[idx])->type == NODE_NO_TYPE)
		{
			str = ((t_node *)json_object->array[idx])->content;
			if (ft_strchr("{[", *str) != NULL)
			{
				indexes[OPEN_BRACKETS] = idx;
				open_bracket_char = *str;
			}
			else if ((*str == '}' && open_bracket_char == '{')
				|| (*str == ']' && open_bracket_char == '['))
			{
				indexes[CLOSING_BRACKETS] = idx;
				break ;
			}
		}
		idx++;
	}
}

static int	_get_open_bracket(t_vla *json_object, size_t open_idx)
{
	t_node	*open_bracket_node;

	open_bracket_node = json_object->array[open_idx];
	return (*(char *)(open_bracket_node->content));
}

t_vla	*convert_token_to_json_object(t_vla *token)
{
	t_vla	*json_object;
	size_t	indexes[BRACKETS];
	int		open_bracket;

	json_object = prepere_json_object(token);
	while (json_object->size != 1)
	{
		_set_indexes(json_object, indexes);
		open_bracket = _get_open_bracket(json_object, indexes[OPEN_BRACKETS]);
		if (open_bracket == '{')
			convert_token_to_dict(json_object,
				indexes[OPEN_BRACKETS],
				indexes[CLOSING_BRACKETS] - indexes[OPEN_BRACKETS]);
		else if (open_bracket == '[')
			convert_token_to_list(json_object,
				indexes[OPEN_BRACKETS],
				indexes[CLOSING_BRACKETS] - indexes[OPEN_BRACKETS]);
	}
	return (json_object);
}
