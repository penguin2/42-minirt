/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_additional_parameters.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:08:10 by rikeda            #+#    #+#             */
/*   Updated: 2023/11/17 03:40:01 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "object.h"
#include "parse.h"

int	add_additional_parameters(const t_json_node *json_node, t_object *object)
{
	if (add_bump_map_parameter(json_node, object) == ERROR
		|| add_checkerboard_parameter(json_node, object) == ERROR
		|| add_material_parameter(json_node, object) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
