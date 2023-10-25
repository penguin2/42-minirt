/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_dict_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:52:57 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/25 18:38:18 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "define.h"

int	state_dict_end(t_vla *token, t_vla *stack, size_t idx, int state)
{
	char	*str;

	if (idx == token->size || state == END)
		return (check_state_end(token, idx, state));
	str = (char *)token->array[idx];
	if (state == IN_DICT && *str == '}' && is_state_closed(stack, '}'))
		return (state_dict_end(token, stack, (idx + 1), get_state(stack)));
	else if (state == IN_LIST && *str == ']' && is_state_closed(stack, ']'))
		return (state_list_end(token, stack, (idx + 1), get_state(stack)));
	else if (*str == ',')
		return (state_comma(token, stack, (idx + 1), state));
	else
		return (ERROR);
}
