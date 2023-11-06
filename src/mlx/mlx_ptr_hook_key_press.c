/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_ptr_hook_key_press.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:33:35 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/07 01:47:39 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_ptr.h"
#include <stddef.h>

int	mlx_ptr_hook_key_press(int keycode, t_mlx_ptr *mlx_ptr)
{
	const t_hook	*hooks_kp = mlx_ptr->mlx_hook_helper.hooks_key_press;
	size_t			i;

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
