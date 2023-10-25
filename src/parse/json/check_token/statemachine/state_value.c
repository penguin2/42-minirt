/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:40:13 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/25 18:36:05 by rikeda           ###   ########.fr       */
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
	if (stat == IN_DICT && *str == '}' && is_state_closed(stack, '}'))
		return (state_dict_end(token, stack, (idx + 1), get_state(stack)));
	else if (stat == IN_LIST && *str == ']' && is_state_closed(stack, ']'))
		return (state_list_end(token, stack, (idx + 1), get_state(stack)));
	else if (*str == ',')
		return (state_comma(token, stack, (idx + 1), stat));
	else
		return (ERROR);
}
