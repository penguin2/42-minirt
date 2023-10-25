/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_list_start.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:53:24 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/25 19:39:55 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "define.h"

int	state_list_start(t_vla *token, t_vla *stack, size_t idx, int state)
{
	char	*str;

	if (idx == token->size || state == END)
		return (check_state_end(token, idx, state));
	str = (char *)token->array[idx];
	if (state == IN_LIST && is_state_closed(stack, *str, LIST_END))
		return (state_list_end(token, stack, (idx + 1), get_state(stack)));
	else if (state == IN_LIST && *str == DICT_START)
	{
		ft_vla_append(stack, str);
		return (state_dict_start(token, stack, (idx + 1), IN_DICT));
	}
	else if (state == IN_LIST && *str == LIST_START)
	{
		ft_vla_append(stack, str);
		return (state_list_start(token, stack, (idx + 1), IN_LIST));
	}
	else if (state == IN_LIST && is_value_token(str))
		return (state_value(token, stack, (idx + 1), IN_LIST));
	else
		return (ERROR);
}
