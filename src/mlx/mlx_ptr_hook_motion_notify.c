/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_ptr_hook_motion_notify.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:27:11 by taekklee          #+#    #+#             */
/*   Updated: 2023/10/24 17:01:32 by taekklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "mlx_ptr.h"
#include "utils.h"

int	mlx_ptr_hook_motion_notify(int x, int y, t_mlx_ptr *mlx_ptr)
{
	(void)mlx_ptr;
	(void)x;
	(void)y;
	return (0);
}
