/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_modify.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 19:29:35 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/14 19:53:46 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcolor.h"
#include "libft.h"
#include "define.h"
#include "plane.h"
#include "mlx_command_mode.h"
#include "identifer_and_parameter.h"
#include "message_parse.h"
#include "range.h"
#include "float.h"
#include "parse.h"

static int	_modify(t_mlx_ptr *mlx_ptr, const char *key, const char *value)
{
	t_plane	*plane;

	plane = mlx_ptr->selected_object->ptr;
	if (ft_is_equal_str(key, COORDINATES))
		return (modify_vec3(mlx_ptr,
				&plane->origin, value, range_create(-DBL_MAX, DBL_MAX)));
	if (ft_is_equal_str(key, NORMAL))
		return (modify_vec3_unit(mlx_ptr,
				&plane->system.axis_z, value, range_create(-1.0, 1.0)));
	else
		return (mlx_putcmd(mlx_ptr, CMD_MOD_KEY_FAILED, COLOR_RED, ERROR));
}

int	plane_modify(t_mlx_ptr *mlx_ptr, const char *key, const char *value)
{
	t_plane	*old_plane;
	t_plane	*new_plane;

	if (_modify(mlx_ptr, key, value) == ERROR)
		return (ERROR);
	old_plane = mlx_ptr->selected_object->ptr;
	new_plane = plane_new(old_plane->origin, old_plane->system.axis_z);
	mlx_ptr->selected_object->free_ptr(old_plane);
	mlx_ptr->selected_object->ptr = new_plane;
	return (SUCCESS);
}
