/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_exit_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:09:43 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/06 20:20:22 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_command_mode.h"
#include "libft.h"
#include "message_parse.h"
#include <stdlib.h>

int	mlx_exit_parser(t_mlx_ptr *mlx_ptr, char **strings)
{
	if (ft_strings_len(strings) == 1)
		exit(0);
	else
		return (mlx_error_message_put_cmd_mode(mlx_ptr, CMD_EXIT_FAILD));
}
