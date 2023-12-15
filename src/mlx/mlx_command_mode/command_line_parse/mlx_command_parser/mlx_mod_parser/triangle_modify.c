/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_modify.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 19:29:35 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/14 20:47:31 by rikeda           ###   ########.fr       */
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

static int	_modify(t_mlx_ptr *mlx_ptr, const char *key, const char *value)
{
	t_triangle *const	triangle = mlx_ptr->selected_object->ptr;
	t_vec3				tmp_vertex[3];

	tmp_vertex[0] = triangle->origin;
	tmp_vertex[1] = vec3_add(triangle->origin, triangle->edge[0]);
	tmp_vertex[2] = vec3_add(triangle->origin, triangle->edge[1]);
	if (_vertex_modify(mlx_ptr, key, value, tmp_vertex) == ERROR)
		return (ERROR);
	if (check_triangle_vertex_valid(tmp_vertex))
		return (mlx_putcmd(mlx_ptr, CMD_MOD_VALUE_FAILED, COLOR_RED, ERROR));
	triangle->origin = tmp_vertex[0];
	triangle->edge[0] = tmp_vertex[1];
	triangle->edge[1] = tmp_vertex[2];
	return (SUCCESS);
}

int	triangle_modify(t_mlx_ptr *mlx_ptr, const char *key, const char *value)
{
	t_triangle	*old_triangle;
	t_triangle	*new_triangle;
	t_vec3		vertex[3];

	if (_modify(mlx_ptr, key, value) == ERROR)
		return (ERROR);
	old_triangle = mlx_ptr->selected_object->ptr;
	vertex[0] = old_triangle->origin;
	vertex[1] = old_triangle->edge[0];
	vertex[2] = old_triangle->edge[1];
	new_triangle = triangle_new(vertex);
	mlx_ptr->selected_object->free_ptr(old_triangle);
	mlx_ptr->selected_object->ptr = new_triangle;
	return (SUCCESS);
}
