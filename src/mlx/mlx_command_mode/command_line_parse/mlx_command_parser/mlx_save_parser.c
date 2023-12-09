/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_save_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:09:43 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/09 18:28:08 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_command_mode.h"
#include "define.h"
#include "libft.h"
#include "generator.h"
#include "message_parse.h"
#include <unistd.h>

int	mlx_save_parser(t_mlx_ptr *mlx_ptr, char **strings)
{
	const char	*file_name = strings[1];
	int			fd;

	if (ft_strings_len(strings) != 2)
		return (mlx_putcmd(mlx_ptr, CMD_SAVE_FAILD, COLOR_RED, ERROR));
	else if (check_extension(file_name, JSON_EXTENSION) == ERROR)
		return (mlx_putcmd(mlx_ptr, CMD_INVALID_EXTENSION, COLOR_RED, ERROR));
	fd = open(file_name, O_WRITE, OPEN_MODE);
	if (fd == -1)
		return (mlx_putcmd(mlx_ptr, CMD_OPEN_FAILED, COLOR_RED, ERROR));
	json_generator_from_scene(mlx_ptr->scene, fd);
	close(fd);
	return (mlx_putcmd(mlx_ptr, CMD_SAVE_SUCCESS, COLOR_GREEN, SUCCESS));
}
