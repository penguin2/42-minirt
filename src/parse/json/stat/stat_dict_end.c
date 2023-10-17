/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat_dict_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:52:57 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/17 20:38:52 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "define.h"

int	stat_dict_end(t_vla *token, t_vla *stack, size_t idx, int stat)
{
	char	*str;

	if (stat == END)
		return (stat_check_end(token, idx));
	str = (char *)token->array[idx];
	if (stat == DICT && *str == '}' && *(char *)ft_vla_pop(stack) == '{')
		return (stat_dict_end(token, stack, (idx + 1), stat_get(stack)));
	else if (stat == DICT && *str == ',')
		return (stat_comma(token, stack, (idx + 1), DICT));
	else
		return (ERROR);
}
