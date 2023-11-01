/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_lights.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:08:22 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/01 14:04:17 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generator.h"
#include "define.h"

int	append_lights(const t_json_node *node, t_vla *lights)
{
	if (append_object_to_vla(node, lights, ID_AMBIENT, append_ambient) == ERROR
		|| append_object_to_vla(node, lights, ID_SPOT, append_spot) == ERROR)
		return (ERROR);
	else
		return (SUCCESS);
}
