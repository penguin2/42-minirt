/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_ptr_hook_key_release.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:33:35 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/26 22:00:13 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_ptr.h"

int	mlx_ptr_hook_key_release(int keycode, t_mlx_ptr *mlx_ptr)
{
	int	i;

	i = 0;
	while (i < HOOK_KEY_RELEASE_CNT)
	{
		if (keycode == mlx_ptr->mlx_hook_helper.key_release[i])
		{
			(*mlx_ptr->mlx_hook_helper.key_release_fn[i])(mlx_ptr, keycode);
			break ;
		}
		++i;
	}
	return (0);
}
