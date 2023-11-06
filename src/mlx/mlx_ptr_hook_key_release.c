/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_ptr_hook_key_release.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:33:35 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/07 01:34:48 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_ptr.h"
#include <stddef.h>

int	mlx_ptr_hook_key_release(int keycode, t_mlx_ptr *mlx_ptr)
{
	const t_hook	*hooks_kr = mlx_ptr->mlx_hook_helper.hooks_key_release;
	size_t			i;

	i = 0;
	while (i < HOOK_KEY_RELEASE_CNT)
	{
		if (keycode == hooks_kr[i].identifier)
		{
			(*(t_fn_key_hook)(hooks_kr[i].handler))(mlx_ptr, keycode);
			break ;
		}
		++i;
	}
	return (0);
}
