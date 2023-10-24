/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_ptr_hook_button_release.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:25:56 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/23 17:57:35 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_ptr.h"

int	mlx_ptr_hook_button_release(int button, int x, int y, t_mlx_ptr *mlx_ptr)
{
	int	i;

	i = 0;
	while (i < HOOK_BUTTON_RELEASE_CNT)
	{
		if (button == mlx_ptr->mlx_hook_helper.button_release[i])
		{
			mlx_ptr->mlx_hook_helper.button_release_fn[i](mlx_ptr, x, y);
			break ;
		}
		++i;
	}
	return (0);
}
