/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_fn_select_object.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:04:49 by taekklee          #+#    #+#             */
/*   Updated: 2023/12/13 14:03:35 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_command_mode.h"
#include "message_parse.h"
#include "object.h"
#include "define.h"
#include "utils.h"

void	hook_fn_select_object(t_mlx_ptr *mlx_ptr, int x, int y)
{
	t_object	*closest;

	closest = (t_object *)object_get_closest(
			get_viewport_ray(&mlx_ptr->scene->camera, y, x),
			&mlx_ptr->scene->objects
			);
	if (closest != NULL)
	{
		mlx_ptr->selected_object = closest;
		mlx_putcmd(mlx_ptr, CMD_SELECTED, COLOR_GREEN, SUCCESS);
	}
}
