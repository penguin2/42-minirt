/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_modify.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 19:29:35 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/12 15:48:18 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcolor.h"
#include "libft.h"
#include "define.h"
#include "libvec3.h"
#include "triangle.h"
#include "mlx_command_mode.h"
#include "identifer_and_parameter.h"
#include "message_parse.h"
#include "range.h"
#include "float.h"
#include "parse.h"
#include "utils.h"
#include <math.h>

static bool	_is_two_vecs_aligned(t_vec3 vec1, t_vec3 vec2)
{
	const double	dot = vec3_dot(vec3_unit(vec1), vec3_unit(vec2));

	return (is_zero(fabs(dot) - 1));
}

static int	_check_triangle_vertex_valid(t_vec3 vertex[3], t_mlx_ptr *mlx_ptr)
{
	t_vec3	edge[2];

	edge[0] = vec3_sub(vertex[1], vertex[0]);
	edge[1] = vec3_sub(vertex[2], vertex[0]);
	if (is_zero(vec3_len(edge[0])) || is_zero(vec3_len(edge[1]))
		|| _is_two_vecs_aligned(edge[0], edge[1]))
	{
		mlx_putcmd(mlx_ptr, CMD_MOD_VALUE_FAILED, COLOR_RED, ERROR);
		return (ERROR);
	}
	return (SUCCESS);
}

static int	_vertex_modify(t_mlx_ptr *mlx_ptr,
							t_vec3 *vertex,
							const char *value)
{
	const t_range	range_vertex = range_create(-DBL_MAX, DBL_MAX);

	return (modify_vec3(mlx_ptr, vertex, value, range_vertex));
}

static void	_copy_from_tmp_to_triangle(t_vec3 vertex[3], t_triangle *triangle)
{
	triangle->origin = vertex[0];
	triangle->edge[0] = vec3_sub(vertex[1], vertex[0]);
	triangle->edge[1] = vec3_sub(vertex[2], vertex[0]);
}

int	triangle_modify(t_mlx_ptr *mlx_ptr, const char *key, const char *value)
{
	t_triangle *const	triangle = mlx_ptr->selected_object->ptr;
	t_vec3				tmp_vertex[3];
	int					success_or_error;
	t_color				*color;

	color = &mlx_ptr->selected_object->color;
	tmp_vertex[0] = triangle->origin;
	tmp_vertex[1] = vec3_add(triangle->origin, triangle->edge[0]);
	tmp_vertex[2] = vec3_add(triangle->origin, triangle->edge[1]);
	if (ft_is_equal_str(key, COLORS))
		return (modify_color(
				mlx_ptr, color, value, range_create(0, MAX_COLOR_8BIT)));
	else if (ft_is_equal_str(key, VERTEX1))
		success_or_error = _vertex_modify(mlx_ptr, &tmp_vertex[0], value);
	else if (ft_is_equal_str(key, VERTEX2))
		success_or_error = _vertex_modify(mlx_ptr, &tmp_vertex[1], value);
	else if (ft_is_equal_str(key, VERTEX3))
		success_or_error = _vertex_modify(mlx_ptr, &tmp_vertex[2], value);
	else
		return (mlx_putcmd(mlx_ptr, CMD_MOD_KEY_FAILED, COLOR_RED, ERROR));
	if (success_or_error == ERROR
		|| _check_triangle_vertex_valid(tmp_vertex, mlx_ptr))
		return (ERROR);
	_copy_from_tmp_to_triangle(tmp_vertex, triangle);
	return (SUCCESS);
}
