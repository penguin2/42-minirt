/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_json_object.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:53:17 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/28 17:26:35 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

/**
* @brief Convert from vla of tokens to vla of token_node
*
* @param token vla of tokens
*
* @return vla of token_node
*/
t_vla	*prepere_json_object(t_vla *token)
{
	size_t		idx;
	t_json_node	*node;
	void		**array;

	array = token->array;
	idx = 0;
	while (idx < token->size)
	{
		node = json_node_new(NULL, array[idx], NODE_NO_TYPE);
		array[idx] = node;
		idx++;
	}
	return (token);
}
