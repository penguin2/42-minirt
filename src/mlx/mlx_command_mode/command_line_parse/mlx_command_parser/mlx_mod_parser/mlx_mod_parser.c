/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_mod_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:01:11 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/14 20:01:13 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx_command_mode.h"
#include "message_parse.h"
#include "define.h"
#include "object.h"
#include "identifer_and_parameter.h"

static int	_modify_object(t_mlx_ptr *mlx_ptr,
						const char *key,
						const char *value)
{
	const t_object	*object = mlx_ptr->selected_object;
	const int		id = object->get_id();

	if (ft_is_equal_str(key, COLORS))
		return (modify_color(mlx_ptr, &mlx_ptr->selected_object->color,
				value, range_create(0, MAX_COLOR_8BIT)));
	else if (id == OBJECT_ID_PLANE)
		return (plane_modify(mlx_ptr, key, value));
	else if (id == OBJECT_ID_SPHERE)
		return (sphere_modify(mlx_ptr, key, value));
	else if (id == OBJECT_ID_CYLINDER)
		return (cylinder_modify(mlx_ptr, key, value));
	else if (id == OBJECT_ID_QUADRIC)
		return (quadric_modify(mlx_ptr, key, value));
	else if (id == OBJECT_ID_TRIANGLE)
		return (triangle_modify(mlx_ptr, key, value));
	return (ERROR);
}

int	mlx_mod_parser(t_mlx_ptr *mlx_ptr, char **strings)
{
	if (3 != ft_strings_len(strings))
		return (mlx_putcmd(mlx_ptr, CMD_MOD_FAILED, COLOR_RED, ERROR));
	if (mlx_ptr->selected_object == NULL)
		return (mlx_putcmd(mlx_ptr, CMD_NOT_SELECT, COLOR_RED, ERROR));
	return (_modify_object(mlx_ptr, strings[1], strings[2]));
}
