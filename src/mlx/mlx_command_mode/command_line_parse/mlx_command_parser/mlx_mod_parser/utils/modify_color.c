/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:12:16 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/14 17:40:02 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "libft.h"
#include "generator.h"
#include "mlx_command_mode.h"
#include "message_parse.h"

int	modify_color(t_mlx_ptr *mlx_ptr,
				t_color *color,
				const char *value,
				t_range range)
{
	char	**strings;
	t_color	tmp_color;

	strings = ft_split_keeping_delimiters(value, RT_VECTOR_SEPARATOR);
	if (ft_strings_len(strings) != 5)
	{
		ft_free_strings(strings);
		return (mlx_putcmd(mlx_ptr, CMD_MOD_VALUE_FAILED, COLOR_RED, ERROR));
	}
	else if (modify_double(mlx_ptr, &tmp_color.red, strings[0], range) == ERROR
		|| modify_double(mlx_ptr, &tmp_color.green, strings[2], range) == ERROR
		|| modify_double(mlx_ptr, &tmp_color.blue, strings[4], range) == ERROR)
	{
		ft_free_strings(strings);
		return (ERROR);
	}
	color->red = tmp_color.red / MAX_COLOR_8BIT;
	color->green = tmp_color.green / MAX_COLOR_8BIT;
	color->blue = tmp_color.blue / MAX_COLOR_8BIT;
	ft_free_strings(strings);
	return (SUCCESS);
}
