/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_closed.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:05:04 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/18 15:09:13 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

bool	is_closed(t_vla *stack, int close_char)
{
	int	open_char;

	open_char = *(char *)ft_vla_pop(stack);
	if (open_char == '{' && close_char == '}')
		return (true);
	else if (open_char == '[' && close_char == ']')
		return (true);
	else
		return (false);
}
