/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_state_closed.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:05:04 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/25 19:39:21 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

/**
* @brief determine if parentheses are closed
*
* @param stack open_brackets stack
* @param close_char } or ] 
*
* @return true if the parenthesis is closed, false otherwise
*/
bool	is_state_closed(t_vla *stack, int c, int close_char)
{
	int	open_char;

	if (c != close_char)
		return (false);
	open_char = *(char *)ft_vla_pop(stack, (stack->size - 1));
	if (open_char == DICT_START && close_char == DICT_END)
		return (true);
	else if (open_char == LIST_START && close_char == LIST_END)
		return (true);
	else
		return (false);
}
