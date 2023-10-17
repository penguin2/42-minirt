/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:39:57 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/17 21:04:12 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "define.h"

int	stat_key(t_vla *token, t_vla *stack, size_t idx, int stat)
{
	char	*str;

	if (stat == END)
		return (stat_check_end(token, idx));
	str = (char *)token->array[idx];
	if (stat == DICT && *str == ':')
		return (stat_colon(token, stack, (idx + 1), DICT));
	else
		return (ERROR);
}
