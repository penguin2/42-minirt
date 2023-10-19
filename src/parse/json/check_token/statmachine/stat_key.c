/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:39:57 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/19 16:51:31 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "define.h"

int	stat_key(t_vla *token, t_vla *stack, size_t idx, int stat)
{
	char	*str;

	if (idx == token->size || stat == END)
		return (check_stat_end(token, idx, stat));
	str = (char *)token->array[idx];
	if (stat == IN_DICT && *str == ':')
		return (stat_colon(token, stack, (idx + 1), IN_DICT));
	else
		return (ERROR);
}
