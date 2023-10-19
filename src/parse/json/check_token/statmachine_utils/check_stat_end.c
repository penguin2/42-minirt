/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stat_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:24:11 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/19 16:50:32 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "define.h"

int	check_stat_end(t_vla *token, size_t idx, int stat)
{
	if (idx == token->size && stat == END)
		return (SUCCESS);
	return (ERROR);
}
