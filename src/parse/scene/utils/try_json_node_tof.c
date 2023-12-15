/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_json_node_tof.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:46:00 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/14 17:50:32 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	try_json_node_tof(const t_json_node *node, double *dptr)
{
	return (try_atof_limit(node->value, dptr, DOUBLE_LIMIT_DIGIT));
}
