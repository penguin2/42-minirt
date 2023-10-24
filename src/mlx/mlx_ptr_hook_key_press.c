/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_ptr_hook_key_press.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:33:35 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/24 17:46:20 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_ptr.h"

int	mlx_ptr_hook_key_press(int keycode, t_mlx_ptr *mlx_ptr)
{
	int	i;

	i = 0;
	while (i < HOOK_KEY_PRESS_CNT)
	{
		if (keycode == mlx_ptr->mlx_hook_helper.key_press[i])
		{
			(*mlx_ptr->mlx_hook_helper.key_press_fn[i])(mlx_ptr, keycode);
			break ;
		}
		++i;
	}
	return (0);
}
