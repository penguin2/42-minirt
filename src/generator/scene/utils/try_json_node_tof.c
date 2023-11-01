/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_json_node_tof.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:46:00 by rikeda            #+#    #+#             */
/*   Updated: 2023/10/30 20:45:22 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generator.h"

int	try_json_node_tof(const t_json_node *node, double *dptr)
{
	const char	*nptr = node->value;

	return (try_atof_limit(nptr, dptr, ATOF_LIMIT));
}
