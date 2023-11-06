/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_ptr_hook_button_press.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:22:48 by taekklee          #+#    #+#             */
/*   Updated: 2023/11/07 01:34:59 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_ptr.h"
#include <stddef.h>

int	mlx_ptr_hook_button_press(int button, int x, int y, t_mlx_ptr *mlx_ptr)
{
	const t_hook	*hooks_bp = mlx_ptr->mlx_hook_helper.hooks_button_press;
	size_t			i;

	i = 0;
	while (i < HOOK_BUTTON_PRESS_CNT)
	{
		if (button == hooks_bp[i].identifier)
		{
			(*(t_fn_button_hook)(hooks_bp[i].handler))(mlx_ptr, x, y);
			break ;
		}
		++i;
	}
	return (0);
}
