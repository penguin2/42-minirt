/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_file_dump.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:22:56 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/13 16:20:29 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_command_mode.h"
#include "define.h"
#include "libgnl.h"
#include <stdlib.h>
#include <mlx.h>

static void	_replace_blank_char_to_space(char *line)
{
	while (*line != '\0')
	{
		if (ft_strchr(MLX_BLANK_STR, *line) != NULL)
			*line = ' ';
		line++;
	}
}

void	mlx_file_dump(t_mlx_ptr *mlx_ptr, int fd)
{
	char	*line;
	size_t	idx;

	mlx_ptr->is_to_update = false;
	idx = 0;
	while (idx++ < (WDW_HEIGHT / WDW_CMD_HEIGHT - 2))
	{
		line = get_next_line(fd, NULL, GNL_MODE_NEWLINE);
		if (line == NULL)
		{
			get_next_line(fd, NULL, GNL_MODE_RESET);
			return ;
		}
		_replace_blank_char_to_space(line);
		mlx_string_put(mlx_ptr->ptr, mlx_ptr->wdw_ptr, (WDW_WIDTH / 100),
			(idx * WDW_CMD_HEIGHT), COLOR_WHITE, line);
		free(line);
	}
	get_next_line(fd, NULL, GNL_MODE_RESET);
	mlx_string_put(mlx_ptr->ptr, mlx_ptr->wdw_ptr, (WDW_WIDTH / 100),
		(idx * WDW_CMD_HEIGHT), COLOR_WHITE, MLX_DUMP_END_STR);
}
