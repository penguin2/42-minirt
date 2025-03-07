/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_exit_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:09:43 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/13 14:26:03 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_command_mode.h"
#include "define.h"
#include "message_parse.h"
#include <stdlib.h>

int	mlx_exit_parser(t_mlx_ptr *mlx_ptr, char **strings)
{
	if (ft_strings_len(strings) == 1)
		exit(EXIT_SUCCESS);
	return (mlx_putcmd(mlx_ptr, CMD_EXIT_FAILED, COLOR_RED, ERROR));
}
