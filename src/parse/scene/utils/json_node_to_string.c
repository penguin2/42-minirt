/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_node_to_string.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:58:46 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/28 22:39:06 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "parse.h"
#include "message_parse.h"
#include "utils.h"

/**
* @brief convert the quoted string wrapped by the given node to unquoted one
*        (and it allocates the memory to store the converted one)
*
* @param node node with the quoted string expected
* @param str pointer to store the converted string
*
* @return SUCCESS if the conversion is successful, otherwise ERROR
*/
int	json_node_to_string(const t_json_node *node, char **str)
{
	if (node == NULL || node->type != NODE_VALUE
		|| !is_with_double_quotes(node->value))
		return (error_with_message_if(true, INVALID_PARAMETERS));
	*str = remove_double_quotes(node->value);
	return (SUCCESS);
}
