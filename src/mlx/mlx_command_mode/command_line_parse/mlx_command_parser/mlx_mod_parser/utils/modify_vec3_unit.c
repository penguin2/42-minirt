/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_vec3_unit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:12:16 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/11 16:24:20 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "libft.h"
#include "generator.h"
#include "libvec3.h"
#include "mlx_command_mode.h"

int	modify_vec3_unit(t_mlx_ptr *mlx_ptr,
				t_vec3 *vec,
				const char *value,
				t_range range)
{
	t_vec3	tmp_vec;

	if (modify_vec3(mlx_ptr, &tmp_vec, value, range) == ERROR)
		return (ERROR);
	if (try_vec3_unit(&tmp_vec) == ERROR)
		return (ERROR);
	*vec = tmp_vec;
	return (SUCCESS);
}
