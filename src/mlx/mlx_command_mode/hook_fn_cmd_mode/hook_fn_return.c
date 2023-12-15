/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_fn_return.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:09:49 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/06 17:35:58 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx_command_mode.h"
#include <unistd.h>

void	hook_fn_return(t_mlx_ptr *mlx_ptr, int keycode)
{
	char	**strings;

	(void)keycode;
	exit_cmd_mode(mlx_ptr);
	strings = ft_split(&mlx_ptr->buffer[1], MLX_BUFFER_SPACE_STR);
	parse_mlx_command_line(mlx_ptr, strings);
	ft_free_strings(strings);
}
