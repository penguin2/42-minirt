/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_list_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:53:45 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/25 19:41:20 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "define.h"

int	state_list_end(t_vla *token, t_vla *stack, size_t idx, int state)
{
	char	*str;

	if (idx == token->size || state == END)
		return (check_state_end(token, idx, state));
	str = (char *)token->array[idx];
	if (state == IN_DICT && is_state_closed(stack, *str, DICT_END))
		return (state_dict_end(token, stack, (idx + 1), get_state(stack)));
	else if (state == IN_LIST && is_state_closed(stack, *str, LIST_END))
		return (state_list_end(token, stack, (idx + 1), get_state(stack)));
	else if (*str == COMMA)
		return (state_comma(token, stack, (idx + 1), state));
	else
		return (ERROR);
}
