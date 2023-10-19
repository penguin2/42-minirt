/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_closed.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:05:04 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/25 14:34:54 by rikeda           ###   ########.fr       */
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
bool	is_stat_closed(t_vla *stack, int close_char)
{
	int	open_char;

	open_char = *(char *)ft_vla_pop(stack, (stack->size - 1));
	if (open_char == '{' && close_char == '}')
		return (true);
	else if (open_char == '[' && close_char == ']')
		return (true);
	else
		return (false);
}
