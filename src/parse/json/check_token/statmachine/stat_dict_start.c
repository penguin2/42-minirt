/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat_dict_start.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:52:09 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/19 16:53:45 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "define.h"

int	stat_dict_start(t_vla *token, t_vla *stack, size_t idx, int stat)
{
	char	*str;

	if (idx == token->size || stat == END)
		return (check_stat_end(token, idx, stat));
	str = (char *)token->array[idx];
	if (stat == IN_DICT && *str == '}' && is_closed(stack, '}'))
		return (stat_dict_end(token, stack, (idx + 1), get_stat(stack)));
	else if (stat == IN_DICT && *str == '\"')
		return (stat_key(token, stack, (idx + 1), IN_DICT));
	else
		return (ERROR);
}
