/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_ptr_hook_button_press.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:22:48 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/24 17:46:53 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_ptr.h"

int	mlx_ptr_hook_button_press(int button, int x, int y, t_mlx_ptr *mlx_ptr)
{
	int	i;

	i = 0;
	while (i < HOOK_BUTTON_PRESS_CNT)
	{
		if (button == mlx_ptr->mlx_hook_helper.button_press[i])
		{
			mlx_ptr->mlx_hook_helper.button_press_fn[i](mlx_ptr, x, y);
			break ;
		}
		++i;
	}
	return (0);
}
