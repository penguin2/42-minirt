/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_fn_set_button_left_off.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:19:04 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/26 19:13:26 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_ptr.h"

void	hook_fn_set_button_left_off(void *_mlx_ptr, int x, int y)
{
	((t_mlx_ptr *)_mlx_ptr)->is_button_left_pressed = false;
	(void)x;
	(void)y;
}
