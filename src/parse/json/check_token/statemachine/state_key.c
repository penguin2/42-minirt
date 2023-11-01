/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:39:57 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/25 19:29:32 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "define.h"

int	state_key(t_vla *token, t_vla *stack, size_t idx, int state)
{
	char	*str;

	if (idx == token->size || state == END)
		return (check_state_end(token, idx, state));
	str = (char *)token->array[idx];
	if (state == IN_DICT && *str == COLON)
		return (state_colon(token, stack, (idx + 1), IN_DICT));
	else
		return (ERROR);
}
