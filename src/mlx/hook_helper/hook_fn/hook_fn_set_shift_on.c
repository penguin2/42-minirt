/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_fn_set_shift_on.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 22:09:07 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/26 22:12:50 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_ptr.h"

void	hook_fn_set_shift_on(t_mlx_ptr *mlx_ptr, int keycode)
{
	mlx_ptr->is_shift_pressed = true;
	(void)keycode;
}
