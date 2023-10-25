/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_comma.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:53:57 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/25 18:37:59 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "define.h"

int	state_comma(t_vla *token, t_vla *stack, size_t idx, int state)
{
	char	*str;

	if (idx == token->size || state == END)
		return (check_state_end(token, idx, state));
	str = (char *)token->array[idx];
	if (state == IN_DICT && *str == '\"')
		return (state_key(token, stack, (idx + 1), IN_DICT));
	else if (state == IN_LIST && *str == '{')
	{
		ft_vla_append(stack, str);
		return (state_dict_start(token, stack, (idx + 1), IN_DICT));
	}
	else if (state == IN_LIST && *str == '[')
	{
		ft_vla_append(stack, str);
		return (state_list_start(token, stack, (idx + 1), IN_LIST));
	}
	else if (state == IN_LIST && is_value_token(str))
		return (state_value(token, stack, (idx + 1), IN_LIST));
	else
		return (ERROR);
}
