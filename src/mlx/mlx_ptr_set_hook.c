/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_ptr_set_hook.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:56:38 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/23 14:58:53 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_ptr.h"
#include <mlx.h>
#include <X11/X.h>
#include <X11/keysym.h>

void	mlx_ptr_set_hook(t_mlx_ptr *mlx_ptr)
{
	mlx_hook(mlx_ptr->wdw_ptr, KeyPress, KeyPressMask,
		mlx_ptr_key_press_hook, mlx_ptr);
}
