/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_token_to_json_object.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:46:40 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/25 14:35:50 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include <stdbool.h>
#include <stddef.h>

static bool	_is_baracket_closed(int open_bracket, int closing_bracket)
{
	if (open_bracket == '{' && closing_bracket == '}')
		return (true);
	else if (open_bracket == '[' && closing_bracket == ']')
		return (true);
	else
		return (false);
}

static int	_get_bracket_char(t_vla *json_object, size_t idx)
{
	t_node	*open_bracket_node;

	open_bracket_node = json_object->array[idx];
	return (*(char *)(open_bracket_node->content));
}

static void	_set_indexes(t_vla *json_object, size_t indexes[BRACKETS])
{
	int		open_bracket;
	int		token_initials;
	size_t	idx;

	idx = 0;
	while (idx < json_object->size)
	{
		if (((t_node *)json_object->array[idx])->type == NODE_NO_TYPE)
		{
			token_initials = _get_bracket_char(json_object, idx);
			if (token_initials == '{' || token_initials == '[')
			{
				indexes[OPEN_BRACKETS] = idx;
				open_bracket = token_initials;
			}
			else if (_is_baracket_closed(open_bracket, token_initials))
			{
				indexes[CLOSING_BRACKETS] = idx;
				break ;
			}
		}
		idx++;
	}
}

t_vla	*convert_token_to_json_object(t_vla *token)
{
	t_vla	*json_object;
	size_t	indexes[BRACKETS];
	int		open_bracket;

	json_object = prepere_json_object(token);
	while (1 < json_object->size)
	{
		_set_indexes(json_object, indexes);
		open_bracket = _get_bracket_char(json_object, indexes[OPEN_BRACKETS]);
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
