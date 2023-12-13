/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_modify.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 19:29:35 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/13 15:09:30 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "triangle.h"
#include "mlx_command_mode.h"
#include "identifer_and_parameter.h"
#include "message_parse.h"
#include "float.h"
#include "utils.h"
#include <math.h>

static void	_copy_from_triangle_to_vertex(t_triangle *triangle, t_vec3 *vertex)
{
	vertex[0] = triangle->origin;
	vertex[1] = vec3_add(triangle->origin, triangle->edge[0]);
	vertex[2] = vec3_add(triangle->origin, triangle->edge[1]);
}

static void	_copy_from_vertex_to_triangle(t_vec3 *vertex, t_triangle *triangle)
{
	triangle->origin = vertex[0];
	triangle->edge[0] = vec3_sub(vertex[1], vertex[0]);
	triangle->edge[1] = vec3_sub(vertex[2], vertex[0]);
}

static int	_vertex_modify(t_mlx_ptr *mlx_ptr,
							const char *key,
							const char *value,
							t_vec3 *tmp_vertex)
{
	const t_range	range_vertex = range_create(-DBL_MAX, DBL_MAX);

	if (ft_is_equal_str(key, VERTEX1))
		return (modify_vec3(mlx_ptr, &tmp_vertex[0], value, range_vertex));
	if (ft_is_equal_str(key, VERTEX2))
		return (modify_vec3(mlx_ptr, &tmp_vertex[1], value, range_vertex));
	if (ft_is_equal_str(key, VERTEX3))
		return (modify_vec3(mlx_ptr, &tmp_vertex[2], value, range_vertex));
	return (mlx_putcmd(mlx_ptr, CMD_MOD_KEY_FAILED, COLOR_RED, ERROR));
}

int	triangle_modify(t_mlx_ptr *mlx_ptr, const char *key, const char *value)
{
	t_triangle *const	triangle = mlx_ptr->selected_object->ptr;
	t_vec3				tmp_vertex[3];
	t_color				*color;

	_copy_from_triangle_to_vertex(triangle, tmp_vertex);
	color = &mlx_ptr->selected_object->color;
	if (ft_is_equal_str(key, COLORS))
		return (modify_color(
				mlx_ptr, color, value, range_create(0, MAX_COLOR_8BIT)));
	else if (_vertex_modify(mlx_ptr, key, value, tmp_vertex) == ERROR)
		return (ERROR);
	if (check_triangle_vertex_valid(tmp_vertex))
		return (mlx_putcmd(mlx_ptr, CMD_MOD_VALUE_FAILED, COLOR_RED, ERROR));
	_copy_from_vertex_to_triangle(tmp_vertex, triangle);
	return (SUCCESS);
}
