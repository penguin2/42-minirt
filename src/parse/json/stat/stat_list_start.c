/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat_list_start.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:53:24 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/18 01:12:25 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "define.h"

int	stat_list_start(t_vla *token, t_vla *stack, size_t idx, int stat)
{
	char	*str;

	if (idx == token->size || stat == END)
		return (stat_check_end(token, idx, stat));
	str = (char *)token->array[idx];
	if (stat == LIST && *str == ']' && *(char *)ft_vla_pop(stack) == '[')
		return (stat_list_end(token, stack, (idx + 1), stat_get(stack)));
	else if (stat == LIST && *str == '{')
	{
		ft_vla_append(stack, str);
		return (stat_dict_start(token, stack, (idx + 1), DICT));
	}
	else if (stat == LIST && *str == '[')
	{
		ft_vla_append(stack, str);
		return (stat_list_start(token, stack, (idx + 1), LIST));
	}
	else if (stat == LIST && is_value_token(str))
		return (stat_value(token, stack, (idx + 1), LIST));
	else
		return (ERROR);
}
