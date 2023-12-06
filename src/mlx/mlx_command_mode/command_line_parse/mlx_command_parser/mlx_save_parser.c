/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_save_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:09:43 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/06 20:34:33 by rikeda           ###   ########.fr       */
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
		return (mlx_error_message_put_cmd_mode(mlx_ptr, CMD_SAVE_FAILD));
	else if (check_extension(strings[1], JSON_EXTENSION) == ERROR)
		return (mlx_error_message_put_cmd_mode(mlx_ptr, CMD_SAVE_NOT_JSON));
	fd = open(file_name, O_WRITE, OPEN_MODE);
	if (fd == -1)
		return (mlx_error_message_put_cmd_mode(mlx_ptr, CMD_OPEN_FAILED));
	json_generator_from_scene(mlx_ptr->scene, fd);
	close(fd);
	return (mlx_success_message_put_cmd_mode(mlx_ptr, CMD_SAVE_SUCCESS));
}
