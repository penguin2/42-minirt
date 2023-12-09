/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_file_dump.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:22:56 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/09 16:57:54 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_command_mode.h"
#include "define.h"
#include <stdlib.h>
#include <mlx.h>

static char	*_replace_tab_to_space(char *line)
{
	char	*new_line;
	size_t	idx;

	new_line = ft_xcalloc(ft_strlen(line) + 1, sizeof(char));
	idx = 0;
	while (line[idx] != '\0')
	{
		if (line[idx] == '\t' || line[idx] == '\n')
			new_line[idx] = ' ';
		else
			new_line[idx] = line[idx];
		idx++;
	}
	free(line);
	return (new_line);
}

void	mlx_file_dump(t_mlx_ptr *mlx_ptr, int fd)
{
	char	*line;
	size_t	idx;

	idx = 0;
	while (idx++ < (WDW_HEIGHT / WDW_CMD_HEIGHT - 2))
	{
		line = get_next_line(fd);
		if (line == NULL)
			return ;
		line = _replace_tab_to_space(line);
		mlx_string_put(mlx_ptr->ptr, mlx_ptr->wdw_ptr, (WDW_WIDTH / 100),
			(idx * WDW_CMD_HEIGHT), COLOR_WHITE, line);
		free(line);
	}
	mlx_string_put(mlx_ptr->ptr, mlx_ptr->wdw_ptr, (WDW_WIDTH / 100),
		(idx * WDW_CMD_HEIGHT), COLOR_WHITE, MLX_DUMP_END_STR);
}
