/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_to_json_value.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:23:20 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/21 21:01:58 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "libft.h"
#include "parse.h"

t_json_node	*double_to_json_list(double n, const char *key)
{
	t_json_node	*value_node;

	value_node = json_node_new(
			ft_strdup(key),
			ft_ftoa(n, DOUBLE_LIMIT_DIGIT),
			NODE_VALUE
			);
	return (value_node);
}
