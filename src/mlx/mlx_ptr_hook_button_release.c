/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_ptr_hook_button_release.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:25:56 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/07 01:34:54 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_ptr.h"
#include <stddef.h>

int	mlx_ptr_hook_button_release(int button, int x, int y, t_mlx_ptr *mlx_ptr)
{
	const t_hook	*hooks_br = mlx_ptr->mlx_hook_helper.hooks_button_release;
	size_t			i;

	i = 0;
	while (i < HOOK_BUTTON_RELEASE_CNT)
	{
		if (button == hooks_br[i].identifier)
		{
			(*(t_fn_button_hook)(hooks_br[i].handler))(mlx_ptr, x, y);
			break ;
		}
		++i;
	}
	return (0);
}
