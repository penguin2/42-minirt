/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat_list_start.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:53:24 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/25 14:51:08 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "define.h"

int	stat_list_start(t_vla *token, t_vla *stack, size_t idx, int stat)
{
	char	*str;

	if (idx == token->size || stat == END)
		return (check_stat_end(token, idx, stat));
	str = (char *)token->array[idx];
	if (stat == IN_LIST && *str == ']' && is_stat_closed(stack, ']'))
		return (stat_list_end(token, stack, (idx + 1), get_stat(stack)));
	else if (stat == IN_LIST && *str == '{')
	{
		ft_vla_append(stack, str);
		return (stat_dict_start(token, stack, (idx + 1), IN_DICT));
	}
	else if (stat == IN_LIST && *str == '[')
	{
		ft_vla_append(stack, str);
		return (stat_list_start(token, stack, (idx + 1), IN_LIST));
	}
	else if (stat == IN_LIST && is_value_token(str))
		return (stat_value(token, stack, (idx + 1), IN_LIST));
	else
		return (ERROR);
}
