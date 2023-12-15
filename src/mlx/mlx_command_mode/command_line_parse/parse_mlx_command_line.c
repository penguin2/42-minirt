/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mlx_command_line.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:25:01 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/13 14:14:58 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "define.h"
#include "mlx_command_mode.h"
#include "message_parse.h"
#include "identifer_and_parameter.h"

static t_fn_mlx_command	_select_command_function(const char *command)
{
	if (ft_is_equal_str(command, CMD_SAVE))
		return (mlx_save_parser);
	else if (ft_is_equal_str(command, CMD_EXIT))
		return (mlx_exit_parser);
	else if (ft_is_equal_str(command, CMD_DUMP))
		return (mlx_dump_parser);
	else if (ft_is_equal_str(command, CMD_HELP))
		return (mlx_help_parser);
	else if (ft_is_equal_str(command, CMD_MOD))
		return (mlx_mod_parser);
	else if (ft_is_equal_str(command, CMD_DEL))
		return (mlx_del_parser);
	return (NULL);
}

int	parse_mlx_command_line(t_mlx_ptr *mlx_ptr, char **strings)
{
	t_fn_mlx_command	command_function;

	if (ft_strings_len(strings) == 0)
		return (mlx_putcmd(mlx_ptr, CMD_EMPTY, COLOR_RED, ERROR));
	command_function = _select_command_function(strings[0]);
	if (command_function == NULL)
		return (mlx_putcmd(mlx_ptr, CMD_NOT_FOUND, COLOR_RED, ERROR));
	return (command_function(mlx_ptr, strings));
}
