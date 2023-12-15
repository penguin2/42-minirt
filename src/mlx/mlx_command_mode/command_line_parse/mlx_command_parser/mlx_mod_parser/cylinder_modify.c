/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_modify.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 19:29:35 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/14 19:54:01 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcolor.h"
#include "libft.h"
#include "define.h"
#include "cylinder.h"
#include "mlx_command_mode.h"
#include "identifer_and_parameter.h"
#include "message_parse.h"
#include "range.h"
#include "float.h"
#include "parse.h"

static int	_modify(t_mlx_ptr *mlx_ptr, const char *key, const char *value)
{
	t_cylinder	*cylinder;

	cylinder = mlx_ptr->selected_object->ptr;
	if (ft_is_equal_str(key, COORDINATES))
		return (modify_vec3(mlx_ptr,
				&cylinder->center, value, range_create(-DBL_MAX, DBL_MAX)));
	else if (ft_is_equal_str(key, AXIS))
		return (modify_vec3_unit(mlx_ptr,
				&cylinder->system.axis_z, value, range_create(-1.0, 1.0)));
	else if (ft_is_equal_str(key, DIAMETER))
		return (modify_double_half(mlx_ptr,
				&cylinder->radius, value, range_create(DBL_MIN, DBL_MAX)));
	else if (ft_is_equal_str(key, HEIGHT))
		return (modify_double_half(mlx_ptr,
				&cylinder->half_height, value, range_create(DBL_MIN, DBL_MAX)));
	else
		return (mlx_putcmd(mlx_ptr, CMD_MOD_KEY_FAILED, COLOR_RED, ERROR));
}

int	cylinder_modify(t_mlx_ptr *mlx_ptr, const char *key, const char *value)
{
	t_cylinder	*old_cylinder;
	t_cylinder	*new_cylinder;

	if (_modify(mlx_ptr, key, value) == ERROR)
		return (ERROR);
	old_cylinder = mlx_ptr->selected_object->ptr;
	new_cylinder = cylinder_new(
			old_cylinder->center,
			old_cylinder->system.axis_z,
			old_cylinder->radius,
			old_cylinder->half_height);
	mlx_ptr->selected_object->free_ptr(old_cylinder);
	mlx_ptr->selected_object->ptr = new_cylinder;
	return (SUCCESS);
}
