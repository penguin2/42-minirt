/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_fn_set_shift_off.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 22:13:15 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/26 22:13:23 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_ptr.h"

void	hook_fn_set_shift_off(t_mlx_ptr *mlx_ptr, int keycode)
{
	mlx_ptr->is_shift_pressed = false;
	(void)keycode;
}
