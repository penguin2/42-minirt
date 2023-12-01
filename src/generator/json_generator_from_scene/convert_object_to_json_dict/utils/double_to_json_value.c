/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_to_json_value.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:23:20 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/01 19:54:56 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generator.h"

t_json_node	*double_to_json_list(double n, const char *key)
{
	char		*copy_key;

	if (key == NULL)
		copy_key = NULL;
	else
		copy_key = ft_strdup(key);
	return (
		json_node_new(
			copy_key,
			ftoa_auto_adjust_when_over_limit(n),
			NODE_VALUE
		)
	);
}
