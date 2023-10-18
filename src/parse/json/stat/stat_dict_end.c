/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat_dict_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:52:57 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/18 12:10:53 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "define.h"

int	stat_dict_end(t_vla *token, t_vla *stack, size_t idx, int stat)
{
	char	*str;

	if (idx == token->size || stat == END)
		return (stat_check_end(token, idx, stat));
	str = (char *)token->array[idx];
	if (stat == IN_DICT && *str == '}' && is_closed(stack, '{'))
		return (stat_dict_end(token, stack, (idx + 1), stat_get(stack)));
	else if (stat == IN_LIST && *str == ']' && is_closed(stack, '['))
		return (stat_list_end(token, stack, (idx + 1), stat_get(stack)));
	else if (*str == ',')
		return (stat_comma(token, stack, (idx + 1), stat));
	else
		return (ERROR);
}
