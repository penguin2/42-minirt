/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_del_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:09:43 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/13 14:25:02 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_command_mode.h"
#include "define.h"
#include "message_parse.h"
#include <stddef.h>

static int	_delete_object(t_mlx_ptr *mlx_ptr)
{
	t_vla		*objects;
	size_t		idx;

	objects = &mlx_ptr->scene->objects;
	idx = 0;
	while (idx < objects->size)
	{
		if (objects->array[idx] == mlx_ptr->selected_object)
		{
			object_free(ft_vla_pop(objects, idx));
			mlx_ptr->selected_object = NULL;
			return (SUCCESS);
		}
		idx++;
	}
	return (ERROR);
}

int	mlx_del_parser(t_mlx_ptr *mlx_ptr, char **strings)
{
	if (ft_strings_len(strings) != 1)
		return (mlx_putcmd(mlx_ptr, CMD_DEL_FAILED, COLOR_RED, ERROR));
	if (mlx_ptr->selected_object == NULL || _delete_object(mlx_ptr) == ERROR)
		return (mlx_putcmd(mlx_ptr, CMD_NOT_SELECT, COLOR_RED, ERROR));
	return (SUCCESS);
}
