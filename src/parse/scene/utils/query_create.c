/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   query_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 20:48:07 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/20 20:48:55 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_query	query_create(
			const t_json_node *json_node,
			const char *key,
			void *value,
			bool is_required)
{
	t_query	new;

	new.json_node = json_node;
	new.key = key;
	new.value = value;
	new.is_required = is_required;
	return (new);
}
