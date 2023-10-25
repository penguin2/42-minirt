/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_state_end.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:24:11 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/25 18:39:33 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "define.h"

int	check_state_end(t_vla *token, size_t idx, int state)
{
	if (idx == token->size && state == END)
		return (SUCCESS);
	return (ERROR);
}
