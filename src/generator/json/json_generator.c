/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_generator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:02:02 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/08 19:19:57 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generator.h"
#include "libft.h"
#include "parse.h"
#include "utils.h"
#include <stdbool.h>
#include <stddef.h>

/**
* @brief output the list side by side
*
* @param master_node Node with type to identify list or dict or value
* @param is_with_newline flag for whether to output newline
* @param fd Output file descriptor
*/
static void	_generator_horizontal_list(t_json_node *master_node,
				bool is_with_newline,
				int fd)
{
	size_t		idx;
	t_json_node	*node;
	t_vla		*json_object;

	json_object = master_node->value;
	ft_putstr_fd(GENERATOR_LIST_START, fd);
	idx = 0;
	while (idx < json_object->size)
	{
		node = json_object->array[idx];
		ft_putstr_fd(node->value, fd);
		idx++;
		if (idx != json_object->size)
			ft_putstr_fd(GENERATOR_VALUE_SEPARATOR, fd);
	}
	ft_putstr_fd(GENERATOR_LIST_END, fd);
	if (is_with_newline)
		ft_putchar_fd('\n', fd);
}

/**
* @brief Format and output json_object
*        If the elements of node of json_object are dict or list, recurse
*        If node of json_object are list and
*        type of value of list are NODE_VALUE, Output horizontally
*
* @param master_node Node with type to identify list or dict or value
* @param nest_level Current nesting depth
* @param fd Output file descriptor
*/
void	json_generator(t_json_node *master_node, size_t nest_level, int fd)
{
	size_t		idx;
	t_json_node	*node;
	t_vla		*json_object;

	json_object = master_node->value;
	if (master_node->type == NODE_LIST && is_only_value_node(json_object))
	{
		_generator_horizontal_list(master_node, nest_level == 0, fd);
		return ;
	}
	put_open_brackets(master_node, fd);
	idx = 0;
	while (idx < json_object->size)
	{
		put_indent((nest_level + 1), fd);
		node = json_object->array[idx];
		if (master_node->type == NODE_DICT)
			put_key_and_colon(node, fd);
		if (node->type == NODE_VALUE)
			ft_putstr_fd(node->value, fd);
		else
			json_generator(node, (nest_level + 1), fd);
		put_value_separator(++idx != json_object->size, fd);
	}
	put_closing_brackets(master_node, nest_level, fd);
}
