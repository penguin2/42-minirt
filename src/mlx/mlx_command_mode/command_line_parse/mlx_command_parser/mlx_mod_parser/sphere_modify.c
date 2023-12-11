/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_modify.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 19:29:35 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/11 20:11:22 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcolor.h"
#include "libft.h"
#include "define.h"
#include "sphere.h"
#include "mlx_command_mode.h"
#include "identifer_and_parameter.h"
#include "message_parse.h"
#include "range.h"
#include "float.h"
#include "parse.h"

int	sphere_modify(t_mlx_ptr *mlx_ptr, const char *key, const char *value)
{
	t_sphere	*sphere;
	t_color		*color;

	sphere = mlx_ptr->selected_object->ptr;
	color = &mlx_ptr->selected_object->color;
	if (ft_is_equal_str(key, COORDINATES))
		return (modify_vec3(mlx_ptr,
				&sphere->center, value, range_create(-DBL_MAX, DBL_MAX)));
	else if (ft_is_equal_str(key, DIAMETER))
		return (modify_double_half(mlx_ptr,
				&sphere->radius, value, range_create(DBL_MIN, DBL_MAX)));
	else if (ft_is_equal_str(key, COLORS))
		return (modify_color(mlx_ptr,
				color, value, range_create(0, MAX_COLOR_8BIT)));
	else
		return (mlx_putcmd(mlx_ptr, CMD_MOD_KEY_FAILED, COLOR_RED, ERROR));
}
