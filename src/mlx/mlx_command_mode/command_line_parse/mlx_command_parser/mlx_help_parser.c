/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_help_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:06:53 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/13 14:28:30 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_command_mode.h"
#include "define.h"
#include "parse.h"
#include "message_parse.h"
#include <unistd.h>
#include <stdlib.h>

static char	*_create_help_file(const char *help_option)
{
	char	*no_extension_file;
	char	*help_file;

	no_extension_file = ft_strjoin(CMD_HELP_DIR, help_option);
	help_file = ft_strjoin(no_extension_file, TXT_EXTENSION);
	free(no_extension_file);
	return (help_file);
}

int	mlx_help_parser(t_mlx_ptr *mlx_ptr, char **strings)
{
	char	*help_file;
	int		fd;

	if (2 < ft_strings_len(strings))
		return (mlx_putcmd(mlx_ptr, CMD_HELP_FAILED, COLOR_RED, ERROR));
	if (ft_strings_len(strings) == 1)
		fd = open(CMD_HELP_TXT_FILE, O_READ);
	else
	{
		help_file = _create_help_file(strings[1]);
		fd = open(help_file, O_READ);
		free(help_file);
	}
	if (fd == -1)
		return (mlx_putcmd(mlx_ptr, CMD_HELP_OPEN_FAILED, COLOR_RED, ERROR));
	reset_image(mlx_ptr, WDW_HEIGHT);
	mlx_file_dump(mlx_ptr, fd);
	close(fd);
	return (SUCCESS);
}
