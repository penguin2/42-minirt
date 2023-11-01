/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_token_to_json_object.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:46:40 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/28 17:25:51 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include <stdbool.h>
#include <stddef.h>

static bool	_is_baracket_closed(int open_bracket, int closing_bracket)
{
	if (open_bracket == DICT_START && closing_bracket == DICT_END)
		return (true);
	else if (open_bracket == LIST_START && closing_bracket == LIST_END)
		return (true);
	else
		return (false);
}

static int	_get_bracket_char(t_vla *json_object, size_t idx)
{
	t_json_node	*open_bracket_node;

	open_bracket_node = json_object->array[idx];
	return (*(char *)(open_bracket_node->value));
}

/**
* @brief Find the open and closing brackets pair and store index in indexes
*
* @param json_object vla of token_node
* Variables to store the index of opening and closing parentheses
* @param indexes Variable to save the index of open and closing brackets
*/
static void	_set_indexes(t_vla *json_object, size_t indexes[BRACKETS])
{
	int		open_bracket;
	int		token_initials;
	size_t	idx;

	idx = 0;
	while (idx < json_object->size)
	{
		if (((t_json_node *)json_object->array[idx])->type == NODE_NO_TYPE)
		{
			token_initials = _get_bracket_char(json_object, idx);
			if (token_initials == DICT_START || token_initials == LIST_START)
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

/**
* @brief Convert vla of tokens to vla with nested dict and list
*
* @param token vla of token_node
*
* @return vla with nested dict and list
*/
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
		if (open_bracket == DICT_START)
			convert_token_to_dict(json_object,
				indexes[OPEN_BRACKETS],
				indexes[CLOSING_BRACKETS] - indexes[OPEN_BRACKETS]);
		else if (open_bracket == LIST_START)
			convert_token_to_list(json_object,
				indexes[OPEN_BRACKETS],
				indexes[CLOSING_BRACKETS] - indexes[OPEN_BRACKETS]);
	}
	return (json_object);
}
