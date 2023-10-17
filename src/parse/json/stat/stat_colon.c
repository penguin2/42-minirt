/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat_colon.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:06:23 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/17 21:17:57 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "define.h"

int	stat_colon(t_vla *token, t_vla *stack, size_t idx, int stat)
{
	char	*str;

	if (stat == END)
		return (stat_check_end(token, idx));
	str = (char *)token->array[idx];
	if (stat == DICT && *str == '{')
	{
		ft_vla_append(stack, str);
		return (stat_dict_start(token, stack, (idx + 1), DICT));
	}
	else if (stat == DICT && *str == '[')
	{
		ft_vla_append(stack, str);
		return (stat_list_start(token, stack, (idx + 1), LIST));
	}
	else if (stat == DICT && ft_strchr("{}[]:,\"", *str) == NULL)
		return (stat_value(token, stack, (idx + 1), DICT));
	else
		return (ERROR);
}
