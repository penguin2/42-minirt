/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_json_object.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:53:17 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/19 18:50:34 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_vla	*prepere_json_object(t_vla *token)
{
	size_t	idx;
	t_node	*node;
	void	**array;

	array = token->array;
	idx = 0;
	while (idx < token->size)
	{
		node = node_new(array[idx], NODE_NO_TYPE);
		array[idx] = node;
		idx++;
	}
	return (token);
}
