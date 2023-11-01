/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_token_to_dict.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:38:59 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/28 17:30:29 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include <stddef.h>
#include <stdlib.h>

static char	*_remove_double_quotation(const char *quoted_str)
{
	char	*removed_str;
	size_t	quoted_str_size;

	quoted_str_size = ft_strlen(quoted_str) - 2;
	removed_str = ft_strndup((quoted_str + 1), quoted_str_size);
	return (removed_str);
}

/**
* @brief Create key_value_node from KEY and VALUE nodes
*        Replacing the value of a KEY node with the key variable of a VALUE node
*        Remove double quote when replacing.
*        CT_START,COLON,COMMA and KEY nodes are free
*
* @param json_object vla of token_node
* @param base_idx Starting index to generate key_vakue_node
*
* @return Node with key and pointer to value and value node type
*/
static t_json_node	*_new_key_value_node(t_vla *json_object, size_t base_idx)
{
	t_json_node	*key_node;
	t_json_node	*value_node;

	json_node_free(ft_vla_pop(json_object, base_idx), free);
	key_node = ft_vla_pop(json_object, base_idx);
	json_node_free(ft_vla_pop(json_object, base_idx), free);
	value_node = ft_vla_pop(json_object, base_idx);
	if (value_node->type == NODE_NO_TYPE)
		value_node->type = NODE_VALUE;
	value_node->key = _remove_double_quotation(key_node->value);
	json_node_free(key_node, free);
	return (value_node);
}

/**
* @brief create a dict and Replace with a vla of token_node
*        Dict is a vla of key_value_nodes created from KEY and VALUE tokens
*
* @param json_object vla of token_node
* @param base_idx Starting index to generate key_vakue_node
* @param size diff between start index and end index to generate key_vakue_node
*
*/
void	convert_token_to_dict(t_vla *json_object, size_t base_idx, size_t size)
{
	t_vla		*dict;
	t_json_node	*node;

	dict = ft_vla_new();
	if (size == PATTERN_NO_CONTENT_IN_DICT)
		json_node_free(ft_vla_pop(json_object, base_idx), free);
	while (1 < size)
	{
		node = _new_key_value_node(json_object, base_idx);
		ft_vla_append(dict, node);
		size -= SIZE_OF_DICT_TOKEN;
	}
	json_node_free(json_object->array[base_idx], free);
	json_object->array[base_idx] = json_node_new(NULL, dict, NODE_DICT);
}
