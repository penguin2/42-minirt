/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:40:13 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/25 19:40:33 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "define.h"

int	state_value(t_vla *token, t_vla *stack, size_t idx, int stat)
{
	char	*str;

	if (idx == token->size || stat == END)
		return (check_state_end(token, idx, stat));
	str = (char *)token->array[idx];
	if (stat == IN_DICT && is_state_closed(stack, *str, DICT_END))
		return (state_dict_end(token, stack, (idx + 1), get_state(stack)));
	else if (stat == IN_LIST && is_state_closed(stack, *str, LIST_END))
		return (state_list_end(token, stack, (idx + 1), get_state(stack)));
	else if (*str == COMMA)
		return (state_comma(token, stack, (idx + 1), stat));
	else
		return (ERROR);
}
