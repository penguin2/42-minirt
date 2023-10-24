/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_fn_set_button_left_on.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:04:49 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/24 17:29:43 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_ptr.h"

void	hook_fn_set_button_left_on(void *mlx_ptr, int x, int y)
{
	((t_mlx_ptr *)mlx_ptr)->is_button_left_pressed = true;
	(void)x;
	(void)y;
}
