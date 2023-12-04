/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bool_to_json_value_node.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 21:17:57 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/04 21:25:02 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "libft.h"
#include <stdbool.h>

const char	*_get_bool_string(bool true_or_false)
{
	if (true_or_false)
		return (TRUE_STRING);
	else
		return (FALSE_STRING);
}

t_json_node	*bool_to_json_value_node(bool true_or_false, const char *key)
{
	const char	*bool_string = _get_bool_string(true_or_false);

	return (
		json_node_new(
			ft_strdup(key),
			ft_strdup(bool_string),
			NODE_VALUE
		)
	);
}
