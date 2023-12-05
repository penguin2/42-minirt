/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_ptr_hook_key_press.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:33:35 by taekklee          #+#    #+#             */
/*   Updated: 2023/12/05 17:53:42 by rikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_ptr.h"
#include <stddef.h>

static int	_mlx_ptr_hook_key_press_cmd_mode(int keycode, t_mlx_ptr *mlx_ptr)
{
	t_hook	*hooks_kp;
	size_t	i;

	hooks_kp = mlx_ptr->mlx_hook_helper.hooks_key_press_cmd_mode;
	i = 0;
	while (i < HOOK_KEY_PRESS_CMD_CNT)
	{
		if (keycode == hooks_kp[i].identifier)
		{
			(*(t_fn_key_hook)(hooks_kp[i].handler))(mlx_ptr, keycode);
			break ;
		}
		++i;
	}
	return (0);
}

int	mlx_ptr_hook_key_press(int keycode, t_mlx_ptr *mlx_ptr)
{
	const t_hook	*hooks_kp = mlx_ptr->mlx_hook_helper.hooks_key_press;
	size_t			i;

	if (mlx_ptr->mode == MLX_MODE_COMMAND)
		return (_mlx_ptr_hook_key_press_cmd_mode(keycode, mlx_ptr));
	i = 0;
	while (i < HOOK_KEY_PRESS_CNT)
	{
		if (keycode == hooks_kp[i].identifier)
		{
			(*(t_fn_key_hook)(hooks_kp[i].handler))(mlx_ptr, keycode);
			break ;
		}
		++i;
	}
	return (0);
}
