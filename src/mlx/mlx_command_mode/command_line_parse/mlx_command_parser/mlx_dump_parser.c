/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_dump_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:09:43 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/06 21:06:56 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_command_mode.h"
#include "libft.h"
#include "message_parse.h"
#include "parse.h"
#include "define.h"
#include <fcntl.h>
#include <stddef.h>
#include <unistd.h>
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

static void	_mlx_file_dump(t_mlx_ptr *mlx_ptr, int fd)
{
	char	*line;
	size_t	idx;

	idx = 0;
	while (idx < (WDW_HEIGHT / WDW_CMD_HEIGHT - 1))
	{
		line = get_next_line(fd);
		if (line == NULL)
			return ;
		line = _replace_tab_to_space(line);
		mlx_string_put(mlx_ptr->ptr, mlx_ptr->wdw_ptr, (WDW_WIDTH / 100.0),
			(idx * WDW_CMD_HEIGHT), MLX_COMMAND_LINE_STD_COLOR, line);
		free(line);
		idx++;
	}
	mlx_string_put(mlx_ptr->ptr, mlx_ptr->wdw_ptr, (WDW_WIDTH / 100.0),
		(idx * WDW_CMD_HEIGHT), MLX_COMMAND_LINE_STD_COLOR, "...");
}

int	mlx_dump_parser(t_mlx_ptr *mlx_ptr, char **strings)
{
	int	fd;

	if (ft_strings_len(strings) != 2)
		return (mlx_error_message_put_cmd_mode(mlx_ptr, CMD_DUMP_FAILD));
	fd = open(strings[1], O_READ);
	if (fd == -1)
		return (mlx_error_message_put_cmd_mode(mlx_ptr, CMD_OPEN_FAILED));
	_mlx_file_dump(mlx_ptr, fd);
	close(fd);
	return (mlx_success_message_put_cmd_mode(mlx_ptr, CMD_DUMP_SUCCESS));
}
