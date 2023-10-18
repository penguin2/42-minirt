/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat_comma.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:53:57 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/18 12:01:21 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "define.h"

int	stat_comma(t_vla *token, t_vla *stack, size_t idx, int stat)
{
	char	*str;

	if (idx == token->size || stat == END)
		return (stat_check_end(token, idx, stat));
	str = (char *)token->array[idx];
	if (stat == IN_DICT && *str == '\"')
		return (stat_key(token, stack, (idx + 1), IN_DICT));
	else if (stat == IN_LIST && *str == '{')
	{
		ft_vla_append(stack, str);
		return (stat_dict_start(token, stack, (idx + 1), IN_DICT));
	}
	else if (stat == IN_LIST && *str == '[')
	{
		ft_vla_append(stack, str);
		return (stat_dict_start(token, stack, (idx + 1), IN_LIST));
	}
	else if (stat == IN_LIST && is_value_token(str))
		return (stat_value(token, stack, (idx + 1), IN_LIST));
	else
		return (ERROR);
}
