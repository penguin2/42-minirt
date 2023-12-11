/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadric_modify.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 19:29:35 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/11 20:11:59 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcolor.h"
#include "libft.h"
#include "define.h"
#include "quadric.h"
#include "mlx_command_mode.h"
#include "identifer_and_parameter.h"
#include "message_parse.h"
#include "range.h"
#include "float.h"
#include "parse.h"

static int	_coeff_array_modify(t_mlx_ptr *mlx_ptr,
								const char *key,
								const char *value)
{
	const t_range	range_coef = range_create(-DBL_MAX, DBL_MAX);
	t_quadric		*quadric;

	quadric = mlx_ptr->selected_object->ptr;
	if (ft_is_equal_str(key, K_A))
		return (modify_double(
				mlx_ptr, &quadric->coeff_array[COEFF_A], value, range_coef));
	else if (ft_is_equal_str(key, K_B))
		return (modify_double(
				mlx_ptr, &quadric->coeff_array[COEFF_B], value, range_coef));
	else if (ft_is_equal_str(key, K_C))
		return (modify_double(
				mlx_ptr, &quadric->coeff_array[COEFF_C], value, range_coef));
	else if (ft_is_equal_str(key, K_D))
		return (modify_double(
				mlx_ptr, &quadric->coeff_array[COEFF_D], value, range_coef));
	else if (ft_is_equal_str(key, K_E))
		return (modify_double(
				mlx_ptr, &quadric->coeff_array[COEFF_E], value, range_coef));
	else
		return (mlx_putcmd(mlx_ptr, CMD_MOD_KEY_FAILED, COLOR_RED, ERROR));
}

int	quadric_modify(t_mlx_ptr *mlx_ptr, const char *key, const char *value)
{
	t_quadric		*quadric;
	t_color			*color;

	quadric = mlx_ptr->selected_object->ptr;
	color = &mlx_ptr->selected_object->color;
	if (ft_is_equal_str(key, COORDINATES))
		return (modify_vec3(mlx_ptr,
				&quadric->center, value, range_create(-DBL_MAX, DBL_MAX)));
	else if (ft_is_equal_str(key, COLORS))
		return (modify_color(mlx_ptr,
				color, value, range_create(0, MAX_COLOR_8BIT)));
	else
		return (_coeff_array_modify(mlx_ptr, key, value));
}
