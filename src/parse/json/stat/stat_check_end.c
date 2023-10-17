/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat_check_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:24:11 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/17 20:25:50 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "define.h"

int	stat_check_end(t_vla *token, size_t idx)
{
	if (token->size == idx)
		return (SUCCESS);
	return (ERROR);
}
