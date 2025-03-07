/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_ptr_set_hook.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:56:38 by taekklee          #+#    #+#             */
/*   Updated: 2023/12/15 19:58:20 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "mlx_ptr.h"
#include <mlx.h>
#include <X11/X.h>
#include <X11/keysym.h>

int	mlx_ptr_set_hook(t_mlx_ptr *mlx_ptr)
{
	mlx_hook(mlx_ptr->wdw_ptr, KeyPress, KeyPressMask,
		mlx_ptr_hook_key_press, mlx_ptr);
	mlx_hook(mlx_ptr->wdw_ptr, KeyRelease, KeyReleaseMask,
		mlx_ptr_hook_key_release, mlx_ptr);
	mlx_hook(mlx_ptr->wdw_ptr, ButtonPress, ButtonPressMask,
		mlx_ptr_hook_button_press, mlx_ptr);
	mlx_hook(mlx_ptr->wdw_ptr,
		MotionNotify, ButtonMotionMask | PointerMotionMask,
		mlx_ptr_hook_motion_notify, mlx_ptr);
	mlx_hook(mlx_ptr->wdw_ptr, Expose, ExposureMask,
		mlx_ptr_hook_expose, mlx_ptr);
	mlx_hook(mlx_ptr->wdw_ptr, DestroyNotify, StructureNotifyMask,
		mlx_ptr_hook_destroy_notify, mlx_ptr);
	return (SUCCESS);
}
