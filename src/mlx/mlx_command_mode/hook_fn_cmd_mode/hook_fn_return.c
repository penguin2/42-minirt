/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_fn_return.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rikeda <rikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:09:49 by rikeda            #+#    #+#             */
/*   Updated: 2023/12/05 17:41:31 by rikeda           ###   ########.fr       */
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
	strings = ft_split(mlx_ptr->buffer, MLX_BUFFER_SPACE_STR);
	if (ft_strings_len(strings) == 0)
		ft_putchar_fd('\a', STDOUT_FILENO);
	ft_free_strings(strings);
}
