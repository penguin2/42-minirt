/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_double.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:12:16 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/11 19:57:40 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "generator.h"
#include "mlx_command_mode.h"
#include "message_parse.h"

int	modify_double(t_mlx_ptr *mlx_ptr,
					double *dptr,
					const char *value,
					t_range range)
{
	double	tmp_double;

	if (try_atof_limit(value, &tmp_double, DOUBLE_LIMIT_DIGIT) == ERROR
		|| !is_between_min_to_max(tmp_double, range.start, range.end))
		return (mlx_putcmd(mlx_ptr, CMD_MOD_VALUE_FAILED, COLOR_RED, ERROR));
	*dptr = tmp_double;
	return (SUCCESS);
}
