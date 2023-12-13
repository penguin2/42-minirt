/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_dump_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:09:43 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/13 14:25:51 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_command_mode.h"
#include "message_parse.h"
#include "parse.h"
#include "define.h"
#include <fcntl.h>
#include <unistd.h>

int	mlx_dump_parser(t_mlx_ptr *mlx_ptr, char **strings)
{
	int	fd;

	if (ft_strings_len(strings) != 2)
		return (mlx_putcmd(mlx_ptr, CMD_DUMP_FAILED, COLOR_RED, ERROR));
	fd = open(strings[1], O_READ);
	if (fd == -1)
		return (mlx_putcmd(mlx_ptr, CMD_OPEN_FAILED, COLOR_RED, ERROR));
	mlx_file_dump(mlx_ptr, fd);
	close(fd);
	return (mlx_putcmd(mlx_ptr, CMD_DUMP_SUCCESS, COLOR_GREEN, SUCCESS));
}
