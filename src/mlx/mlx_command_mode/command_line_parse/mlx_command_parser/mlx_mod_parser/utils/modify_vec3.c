/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_vec3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:12:16 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/11 19:25:53 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "libft.h"
#include "generator.h"
#include "mlx_command_mode.h"

int	modify_vec3(t_mlx_ptr *mlx_ptr,
				t_vec3 *vec,
				const char *value,
				t_range range)
{
	char	**strings;
	t_vec3	tmp_vec;

	strings = ft_split_keeping_delimiters(value, RT_VECTOR_SEPARATOR);
	if (ft_strings_len(strings) != 5
		|| modify_double(mlx_ptr, &tmp_vec.x, strings[0], range) == ERROR
		|| modify_double(mlx_ptr, &tmp_vec.y, strings[2], range) == ERROR
		|| modify_double(mlx_ptr, &tmp_vec.z, strings[4], range) == ERROR)
	{
		ft_free_strings(strings);
		return (ERROR);
	}
	*vec = tmp_vec;
	ft_free_strings(strings);
	return (SUCCESS);
}
