/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_double_half.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:12:16 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/11 19:57:58 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "generator.h"
#include "mlx_command_mode.h"
#include "message_parse.h"

int	modify_double_half(t_mlx_ptr *mlx_ptr,
						double *dptr,
						const char *value,
						t_range range)
{
	if (modify_double(mlx_ptr, dptr, value, range) == ERROR)
		return (ERROR);
	*dptr /= 2.0;
	return (SUCCESS);
}
