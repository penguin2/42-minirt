/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_json_node_tof.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:46:00 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/11 19:50:14 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "message_parse.h"
#include "define.h"
#include "utils.h"

int	try_json_node_tof(const t_json_node *node, double *dptr)
{
	const char	*nptr = node->value;
	int			success_or_error;

	success_or_error = try_atof_limit(nptr, dptr, DOUBLE_LIMIT_DIGIT);
	if (success_or_error == ERROR)
		print_error(ATOF_FAILED);
	return (success_or_error);
}
