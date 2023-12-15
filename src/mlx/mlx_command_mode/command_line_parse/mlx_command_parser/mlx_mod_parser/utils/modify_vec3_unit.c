/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_vec3_unit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:12:16 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/15 16:25:28 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "libft.h"
#include "generator.h"
#include "libvec3.h"
#include "mlx_command_mode.h"
#include "message_parse.h"
#include "define.h"
#include "utils.h"

int	_try_vec3_unit_mlx(t_vec3 *vec)
{
	if (is_zero(vec->x) && is_zero(vec->y) && is_zero(vec->z))
		return (ERROR);
	*vec = vec3_unit(*vec);
	return (SUCCESS);
}

int	modify_vec3_unit(t_mlx_ptr *mlx_ptr,
				t_vec3 *vec,
				const char *value,
				t_range range)
{
	t_vec3	tmp_vec;

	if (modify_vec3(mlx_ptr, &tmp_vec, value, range) == ERROR)
		return (ERROR);
	if (_try_vec3_unit_mlx(&tmp_vec) == ERROR)
		return (mlx_putcmd(mlx_ptr, CMD_MOD_VALUE_FAILED, COLOR_RED, ERROR));
	*vec = tmp_vec;
	return (SUCCESS);
}
