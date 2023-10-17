/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat_dict_start.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:52:09 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/18 01:11:54 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "define.h"

int	stat_dict_start(t_vla *token, t_vla *stack, size_t idx, int stat)
{
	char	*str;

	if (idx == token->size || stat == END)
		return (stat_check_end(token, idx, stat));
	str = (char *)token->array[idx];
	if (stat == DICT && *str == '}' && *(char *)ft_vla_pop(stack) == '{')
		return (stat_dict_end(token, stack, (idx + 1), stat_get(stack)));
	else if (stat == DICT && *str == '\"')
		return (stat_key(token, stack, (idx + 1), DICT));
	else
		return (ERROR);
}
